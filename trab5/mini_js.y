%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <unordered_set>
#include <sstream>

using namespace std;

bool dev = false; // not logging

int ln = 1, col = 0; 

bool isFunctionScope = false;

struct Attributes {
    vector<string> code; 

    int args_counter = 0; 

    vector<string> default_value; 

    int ln = 0, col = 0;

    void clear() {
        code.clear();
        default_value.clear();
        ln = 0;
        col = 0;
        args_counter = 0;
    }
};


#define YYSTYPE Attributes

enum Decl { DeclVar=1, DeclConst, DeclLet };

struct Variable {
  int ln, col;
  Decl type;
};

vector<map<string,Variable>> symbols = { map< string, Variable >{} }; 
vector<string> functions;

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

// log functions ---

void logMessage(std::ostream& os) {}

template <typename T, typename... Args>
void logMessage(ostream& os, T first, Args... args) {
    os << first;
    logMessage(os, args...);
}

template <typename... Args>
void log(Args... args) {
    if (dev) {
        logMessage(cout, args...);
        cout << endl;
    }
}

// -------------------

vector<string> concat(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> resolveAddr(vector<string> code);
string getLabel(string prefix);
void print(vector<string> code);
vector<string> declareVariable(Decl type, Attributes attr);
vector<string> declareVariable(Decl type, string name, int ln, int col);
void verifyAttrib(string name, bool a);
vector<string> vec(string s);
vector<string> declareFunction(Attributes attr);
tuple<string,string,string,string> generateIfLabels();
vector<string> generateDefaultParamsCode(Attributes attr);
string trim(string str, string charsToTrim);
vector<string> getFormattedMdpCode(string mdpCode);

%}

%token AND OR EQUAL GT_EQ LT_EQ DIFF PLUS_EQ PLUS_PLUS EMPTY_BLOCK
%token IF ELSE FOR WHILE LET CONST VAR ASM ARROW ARROW_OBJ
%token STRING INT FLOAT ID FUNCTION RETURN BOOL PARENTESIS_ARROW

%right '='
%nonassoc '<' '>' IF ELSE 
%nonassoc EQUAL GT_EQ PLUS_PLUS
%nonassoc PLUS_EQ LT_EQ DIFF 
%left '+' '-'
%left '*' '/' '%'
%left '(' '[' '{'
%right '.'

%%
S : CMDs { print(resolveAddr($1.code  + "." + functions)); }
  ;

CMDs : CMDs CMD { $$.code = $1.code + $2.code; }
     | {$$.clear();}
     ;

CMD : DECL_LET ';'
    | DECL_CONST ';'
    | DECL_VAR ';'
    | CMD_IF
    | CMD_FOR
    | CMD_WHILE
    | CMD_FUNCTION
    | RETURN E ';' { $$.code = $2.code + "'&retorno'" + "@" + "~"; }
    | E ASM ';' { $$.code = $1.code + $2.code + "^"; }
    | '{' PUSH_SYMBOLS CMDs '}' { symbols.pop_back(); $$.code = vec("<{") + $3.code + vec("}>"); }
    | E ';' { $$.code = $1.code + "^";}
    | ';' { $$.clear(); }
    | EMPTY_BLOCK { $$.clear(); }
    ;

PUSH_SYMBOLS : { symbols.push_back( map< string, Variable >{} ); } 
             ;

CMD_FUNCTION : FUNCTION ID 
                { declareVariable(DeclVar, $2); } 
                { isFunctionScope = true; }
                '(' PUSH_SYMBOLS PARAMS_LIST ')' 
                '{' CMDs '}'
                { isFunctionScope = false; }
                {
                    string lbl_func = getLabel("func_" + $2.code[0]);
                    string def_lbl_func = ":" + lbl_func;
                    // mdc & mdc {} = '&funcao' 21 [=] ^
                    $$.code =  $2.code + "&" + $2.code + 
                        "{}" + "=" + "'&funcao'" + lbl_func + 
                        "[=]" + "^";
                    functions = functions + def_lbl_func + $7.code + $10.code +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
                    symbols.pop_back();
                }

PARAMS_LIST : PARAMS 
            | { $$.clear(); }
            ;

PARAMS : PARAMS ',' PARAM 
        {
            declareVariable(DeclLet, $3);
            $$.code = $1.code + $3.code + "&" + $3.code + "arguments" + "@" 
                + to_string($1.args_counter) + "[@]" + "=" + "^";
            if ($3.default_value.size() > 0) 
                $$.code = $$.code + generateDefaultParamsCode($3);
            $$.args_counter = $1.args_counter + $3.args_counter;
        }
       | PARAM
       {    
            declareVariable(DeclLet, $1);
            $$.code = $1.code + "&" + $1.code + "arguments" + "@" 
                + "0" + "[@]" + "=" + "^";
            if ($1.default_value.size() > 0) 
                $$.code = $$.code + generateDefaultParamsCode($1);
            $$.args_counter = $1.args_counter;
       }

       ;
PARAM   : ID 
            {
                $$.code = $1.code;
                $$.default_value.clear();
                $$.args_counter = 1;
                declareVariable(DeclLet, $1);
            }
        | ID '=' E 
            {
                $$.code = $1.code;
                $$.default_value = $3.code;
                $$.args_counter = 1;
                declareVariable(DeclLet, $1);
            }

CMD_IF : IF '(' E ')' CMD 
    {
        string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
        tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
        $$.code = $3.code + 
                lbl_true + "?" + 
                lbl_end_if + "#" + 
                def_lbl_true + $5.code 
                + def_lbl_end_if; 

    }
    
    | IF '(' E ')' CMD ELSE CMD
    { 
        string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
        tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
        $$.code = $3.code +                     // Codigo da expressão
                lbl_true + "?" +                // Código do IF
                $7.code + lbl_end_if + "#" +    // Código do False
                def_lbl_true + $5.code +        // Código do True
                def_lbl_end_if                  // Fim do IF
                ;
    }

CMD_WHILE : WHILE '(' E ')' CMD 
    {
        string lbl_cond_while = getLabel("lbl_cond_while");
        string def_lbl_cond_while = ":" + lbl_cond_while;
        string lbl_cmd_while = getLabel("lbl_cmd_while");
        string def_lbl_cmd_while = ":" + lbl_cmd_while;
        string lbl_end_while = getLabel("lbl_end_while");
        string def_lbl_end_while = ":" + lbl_end_while;
        
        $$.code = def_lbl_cond_while 
                + $3.code + lbl_cmd_while + "?" 
                + lbl_end_while + "#" 
                + def_lbl_cmd_while + $5.code 
                + lbl_cond_while + "#"
                + def_lbl_end_while;
    }

CMD_FOR : FOR '(' PRIM_E ';' E ';' E ')' CMD 
        { string lbl_fim_for = getLabel( "fim_for" );
          string lbl_condicao_for = getLabel( "condicao_for" );
          string lbl_comando_for = getLabel( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;
          
          $$.code = $3.code + definicao_lbl_condicao_for +
                 $5.code + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + $9.code + 
                 $7.code + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
        ;

PRIM_E : DECL_LET 
       | E  
         { $$.code = $1.code + "^"; }
       ;
    
DECL_LET : LET LET_IDs { $$.code = $2.code; }
         ;
         
LET_IDs : LET_ID ',' LET_IDs { $$.code = $1.code + $3.code; }
        | LET_ID
        ;

LET_ID : ID { $$.code = declareVariable(DeclLet, $1); }
       | ID '=' E {  $$.code = declareVariable(DeclLet, $1) + $1.code + $3.code + "=" + "^"; }
       | ID '=' OBJ {  $$.code = declareVariable(DeclLet, $1) + $1.code + $3.code + "=" + "^"; }
       ;

DECL_CONST : CONST CONST_IDs { $$.code = $2.code; }
         ;

CONST_IDs : CONST_ID ',' CONST_IDs { $$.code = $1.code + $3.code; }
        | CONST_ID
        ;

CONST_ID : ID {  $$.code = declareVariable(DeclConst, $1); }
       | ID '=' E { $$.code = declareVariable(DeclConst, $1) + $1.code + $3.code + "=" + "^"; }
       | ID '=' OBJ {  $$.code = declareVariable(DeclConst, $1) + $1.code + $3.code + "=" + "^"; }
       ;

DECL_VAR : VAR VAR_IDs { $$.code = $2.code; }
         ;

VAR_IDs : VAR_ID ',' VAR_IDs { $$.code = $1.code + $3.code; }
        | VAR_ID
        ;

VAR_ID : ID { $$.code = declareVariable(DeclVar, $1); }
       | ID '=' E { $$.code = declareVariable(DeclVar, $1) + $1.code + $3.code + "=" + "^"; }
       | ID '=' OBJ {  $$.code = declareVariable(DeclVar, $1) + $1.code + $3.code + "=" + "^"; }
       ; 

E   : ID '=' E { verifyAttrib($1.code[0],true); $$.code = $1.code + $3.code + "="; }
    | ID '=' OBJ { verifyAttrib($1.code[0],true); $$.code = $1.code + $3.code + "="; }
    | ID PLUS_PLUS { verifyAttrib($1.code[0], true); $$.code = $1.code + "@" + $1.code + $1.code + "@" + "1" + "+" + "=" + "^"; } // poe o valor da var na pilha. soma, desempilha o resultado.
    | ID PLUS_EQ E { verifyAttrib($1.code[0], true); $$.code = $1.code + $1.code + "@" + $3.code + "+" + "="; }
    | LVALUEPROP '=' E 	{ verifyAttrib($1.code[0], true); $$.code = $1.code + $3.code + "[=]"; }
    | LVALUEPROP PLUS_EQ E { verifyAttrib($1.code[0], true); $$.code = $1.code + $1.code + "[@]" + $3.code + "+" + "[=]"; }
    | E EQUAL E { $$.code = $1.code + $3.code + "=="; }
    | E DIFF E { $$.code = $1.code + $3.code + "!="; }
    | E GT_EQ E { $$.code = $1.code + $3.code + ">="; }
    | E LT_EQ E { $$.code = $1.code + $3.code + "<="; }
    | E '<' E { $$.code = $1.code + $3.code + "<"; }
    | E '>' E { $$.code = $1.code + $3.code + ">"; }
    | E '+' E { $$.code = $1.code + $3.code + "+"; }
    | E '*' E { $$.code = $1.code + $3.code + "*"; }
    | E '/' E { $$.code = $1.code + $3.code + "/"; }
    | E '-' E { $$.code = $1.code + $3.code + "-"; }
    | E '%' E { $$.code = $1.code + $3.code + "%"; }
    | '-' E   { $$.code = "0" + $2.code + $1.code; }
    | '[' ']' { $$.code = vec("[]");               }
    | FLOAT
    | INT
    | BOOL
    | STRING
    | E '(' ARGS_LIST ')'   { 
            $$.code = $3.code + to_string( $3.args_counter ) + $1.code + "$"; 
        }
    | ID 	                { 
            verifyAttrib($1.code[0], false); $$.code = $1.code + "@";         
        }
    | LVALUEPROP            { 
            verifyAttrib($1.code[0], false); $$.code = $1.code + "[@]";      
        }
    | '(' E ')'             { $$.code = $2.code; }
    | '(' OBJ ')'           { $$.code = $2.code; }
    |  ID_ARROW ARROW E     {
            string lbl_func = getLabel("func_" + $1.code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            $$.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                $1.code + "&" + $1.code + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" +
                $3.code + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }
    | ID_ARROW ARROW_OBJ CMDs '}' {
            string lbl_func = getLabel("func_" + $1.code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            $$.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                $1.code + "&" + $1.code + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" +
                $3.code + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }
    | '(' PARAMS_LIST PARENTESIS_ARROW E { 
            string lbl_func = getLabel("func_" + $1.code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            $$.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                $1.code + "&" + $2.code + $4.code
                + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }   
    | ANON_FUNC
    ;
    
LVALUEPROP  :   E '.' ID { $$.code = $1.code + $3.code; }
            |   E '[' E ']' { $$.code = $1.code + $3.code; }
            ;

ARGS_LIST : ARGS
           | { $$.clear(); }
           ;
             
ARGS : ARGS ',' E
        { 
            $$.code = $1.code + $3.code;
            $$.args_counter++; 
        }
     | E
        { 
            $$.code = $1.code;
            $$.args_counter++; 
        }
     ;

ID_ARROW : ID PUSH_SYMBOLS { declareVariable(DeclLet, $1); }
         ;

ANON_FUNC : FUNCTION '(' PUSH_SYMBOLS PARAMS_LIST ')' '{' CMDs '}' 
            {
                string lbl_func = getLabel("func_");
                string def_lbl_func = ":" + lbl_func;
                
                $$.code =  vec("{}") + "'&funcao'" + 
                    lbl_func + "[<=]";
                functions = functions + def_lbl_func + 
                    $4.code + $7.code +
                    "undefined" + "@" + "'&retorno'" + "@"+ "~";
                symbols.pop_back();
            }
         ;	

OBJ : EMPTY_BLOCK
    | '{' OBJ_FIELDS '}' { $$.code = "{}" + $2.code; }
    ;

OBJ_FIELDS : OBJ_FIELDS ',' OBJ_FIELD { $$.code = $1.code + $3.code; }
           | OBJ_FIELD 
           ;

OBJ_FIELD : ID ':' E { $$.code = $1.code + $3.code + "[<=]"; }
          | ID ':' OBJ { $$.code = $1.code + $3.code + "[<=]"; }
          ;

/* ARRAY : '[' ARRAY_ARGS ']' {$$.code = $2.code; }
      ;

ARRAY_ARGS : ARRAY_ARGS ',' ARRAY_ARG { $$.code = $1.code + to_string()} */






%%
#include "lex.yy.c"

vector<string> concat(vector<string> a, vector<string> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

vector<string> operator+(vector<string> a, vector<string> b) {
    return concat(a, b);
}

vector<string> operator+(vector<string> a, string b) {
    a.push_back(b) ;
    return a;
}

vector<string> operator+(string a, vector<string> b) {
    return vector<string>{a} + b;
}

vector<string> resolveAddr(vector<string> code) {
    map<string,int> label;
    vector<string> saida;
    for(int i = 0; i < code.size(); i++){
        if(code[i][0] == ':')
            label[code[i].substr(1)] = saida.size();
        else
            saida.push_back(code[i]);
    }

    for(int i = 0; i < saida.size(); i++){
        if(label.count( saida[i] ) > 0 )
            saida[i] = to_string(label[saida[i]]);
    }

    return saida;
}

string getLabel(string prefix) {
  static int n = 0;
  return prefix + "_" + to_string(++n) + ":";
}

void print(vector<string> code) {
    for(string s : code)
        cout << s << " ";
    cout << endl;
}

vector<string> declareVariable(Decl type, Attributes attr){ 
   log("\nDeclarando variável");
    string name = attr.code[0];
    int ln = attr.ln, col = attr.col;
    log("Nome: ", name);
    log("Tipo: ", type);
    log("Linha: ",ln," Coluna: ",col);

    auto& current = symbols.back();

    if(current.count(name) == 0) {
        current[name] = Variable{ln, col, type};
        return vector<string>{name, "&"};
    }
    if(type == DeclVar && current[name].type == DeclVar ) {
        current[name] = Variable{ln, col, type};
        return vector<string>{};
    } 
    cerr << "Erro: a variável '" << name << "' já foi declarada na linha " << current[name].ln << "." << endl;
    exit(1);     
}

vector<string> declareVariable(Decl type, string name, int ln, int col) {
    Attributes attr = {vec(name), 0, {}, ln, col};
    return declareVariable(type, attr);
}

void verifyAttrib(string name, bool a) {
    if (isFunctionScope) return;

    log("\nVerificando atribuição" );
    log("Nome: " , name );

    for (int i = symbols.size() - 1; i >=0; i--){
        auto& curr = symbols[i];
        log(" ==== escopo nivel " , i , " ====" );
        for (const auto& pair : symbols[i]) {
            log("Key: " , pair.first );
            log("Ln: " , pair.second.ln );
            log("Col: " , pair.second.col );
            log("Type: " , pair.second.type );
            log("====================" );
        }
        log("curr.count(name): " , curr.count(name) );
        if(curr.count(name) > 0) {
            if(a && curr[name].type == DeclConst) {
                cerr << "Erro: a variável '" << name << "' não pode ser modificada." << endl;
                exit(1);     
            }
            else return;   
        }
    }
    cerr << "Erro: a variável '" << name << "' não foi declarada." << endl;
    exit(1);
}

vector<string> vec(string s) {
    return vector<string>{s};
}


tuple<string,string,string,string> generateIfLabels(){
    string lbl_true = getLabel( "lbl_true" );
    string lbl_end_if = getLabel( "lbl_end_if" );
    string def_lbl_true = ":" + lbl_true;
    string def_lbl_end_if = ":" + lbl_end_if;
    return make_tuple(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if);
}

vector<string> generateDefaultParamsCode(Attributes attr){
    string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
    tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
    return declareVariable(DeclVar, "df_name", 1, 1) +
        attr.code + "@" + "df_name" + "@" + "==" +
        lbl_true + "?" + lbl_end_if + "#" + 
        def_lbl_true + attr.code + attr.default_value + "=" + "^" +
        def_lbl_end_if;
}

string trim(string str, string charsToTrim) {
    unordered_set<char> removeSet(charsToTrim.begin(), charsToTrim.end());
    string result = "";
    for (char c : str) 
        if (removeSet.find(c) == removeSet.end()) 
            result += c;
        
    return result;
}

vector<string> getFormattedMdpCode(string mdpCode){
	vector<string> formattedMdp;
	string instr = "";
	for(auto c : mdpCode){
		if(c != ' ')
			instr += c;
		else {
			formattedMdp.push_back(instr);
			instr = "";
		}
	}
	formattedMdp.push_back(instr);
	return formattedMdp;
}

void yyerror( const char* st ) {
    puts( st ); 
    printf( "Proximo a: %s\n", yytext );
    exit( 1 );
}

int main( int argc, char* argv[] ) {
    yyparse();
    
    return 0;
}
