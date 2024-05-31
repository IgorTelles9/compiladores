%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

int ln = 1, col = 0; 

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

vector<string> concat(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
bool operator!=(vector<string> a, vector<string> b);
vector<string> resolveAddr(vector<string> code);
string getLabel(string prefix);
void print(vector<string> code);
vector<string> declareVariable(Decl type, Attributes attr);
vector<string> declareVariable(Decl type, string name, int ln, int col);
void verifyAttrib(string name, bool a);
vector<string> vec(string s);
vector<string> declareFunction(Attributes attr);
tuple<string,string,string,string> generateIfLabels();
vector<string> generateParamsCode(Attributes attr);
string trim(string str, string charsToTrim);
vector<string> getFormattedMdpCode(string mdpCode);

%}

%token AND OR EQUAL GT_EQ LT_EQ DIFF PLUS_EQ PLUS_PLUS
%token OBJ ARRAY IF ELSE FOR WHILE LET CONST VAR ASM
%token PRINT STRING INT FLOAT ID FUNCTION RETURN

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
    ;

PUSH_SYMBOLS : { symbols.push_back( map< string, Variable >{} ); } 
             ;
POP_SYMBOLS  : { symbols.pop_back(); }
             ;

CMD_FUNCTION : FUNCTION ID { declareFunction($2); } '(' PUSH_SYMBOLS PARAMS_LIST ')' '{' CMDs '}'
                {
                    string lbl_func = getLabel("func_" + $2.code[0]);
                    string def_lbl_func = ":" + lbl_func;
                    // mdc & mdc {} = '&funcao' 21 [=] ^
                    $$.code =  $2.code + "&" + $2.code + 
                        "{}" + "=" + "'&funcao'" + lbl_func + 
                        "[=]" + "^";
                    functions = functions + def_lbl_func + $6.code + $9.code +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
                    symbols.pop_back();
                }

PARAMS_LIST : PARAMS 
            | { $$.clear(); }
            ;

PARAMS : PARAMS ',' PARAM 
        {
            $$.code = $1.code + $3.code + "&" + $3.code + "arguments" + "@" 
                + to_string($1.args_counter) + "[@]" + "=" + "^";
            if ($3.default_value.size() > 0) 
                $$.code = $$.code + $3.code + $3.default_value + "=" + "^"; //generateParamsCode($3);
            $$.args_counter = $1.args_counter + $3.args_counter;
        }
       | PARAM
       {
            $$.code = $1.code + "&" + $1.code + "arguments" + "@" 
                + "0" + "[@]" + "=" + "^";
            if ($1.default_value.size() > 0) 
                $$.code = $$.code + $1.code + $1.default_value + "=" + "^"; //generateParamsCode($1);
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
       ;

DECL_CONST : CONST CONST_IDs { $$.code = $2.code; }
         ;

CONST_IDs : CONST_ID ',' CONST_IDs { $$.code = $1.code + $3.code; }
        | CONST_ID
        ;

CONST_ID : ID {  $$.code = declareVariable(DeclConst, $1); }
       | ID '=' E { $$.code = declareVariable(DeclConst, $1) + $1.code + $3.code + "=" + "^"; }
       ;

DECL_VAR : VAR VAR_IDs { $$.code = $2.code; }
         ;

VAR_IDs : VAR_ID ',' VAR_IDs { $$.code = $1.code + $3.code; }
        | VAR_ID
        ;

VAR_ID : ID { $$.code = declareVariable(DeclVar, $1); }
       | ID '=' E { $$.code = declareVariable(DeclVar, $1) + $1.code + $3.code + "=" + "^"; }
       ; 

E : LVALUE '=' E { verifyAttrib($1.code[0],true); $$.code = $1.code + $3.code + "="; }
    | LVALUE PLUS_PLUS { verifyAttrib($1.code[0], true); $$.code = $1.code + "@" + $1.code + $1.code + "@" + "1" + "+" + "=" + "^"; } // poe o valor da var na pilha. soma, desempilha o resultado.
    | LVALUE PLUS_EQ E { verifyAttrib($1.code[0], true); $$.code = $1.code + $1.code + "@" + $3.code + "+" + "="; }
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
    | '{' '}' { $$.code = vec("{}");               }
    | ARRAY   { $$.code = vec("[]");               } 
    | OBJ     { $$.code = vec("{}");               } 
    | FLOAT
    | INT
    | STRING
    | E '(' ARGS_LIST ')'   { $$.code = $3.code + to_string( $3.args_counter ) + $1.code + "$"; }
    | LVALUE 	            { verifyAttrib($1.code[0], false); $$.code = $1.code + "@";         }
    | LVALUEPROP            { verifyAttrib($1.code[0], false); $$.code = $1.code + "[@]";       }
    | '(' E ')'             { $$.code = $2.code;                                                }

LVALUE  :   ID 
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
            $$.args_counter = $1.args_counter + $3.args_counter; 
        }
     | E
        { 
            $$.code = $1.code;
            $$.args_counter = 1; 
        }
     ;
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
    /* cout << "Declarando variável" << endl; */
    string name = attr.code[0];
    int ln = attr.ln, col = attr.col;
    /* cout << "Nome: " << name << endl;
    cout << "Tipo: " << type << endl;
    cout << "Linha: " << ln << " Coluna: " << col << endl; */

    auto& current = symbols.back();
    /* cout << "Current: " << current.size() << endl; */

    if(current.count(name) == 0) {
        current[name] = Variable{ln, col, type};
        /* cout << "Current: " << current.size() << endl; */
        return vector<string>{name, "&"};
    }
    if(type == DeclVar && current[name].type == DeclVar ) {
        current[name] = Variable{ln, col, type};
        return vector<string>{};
    } 
    cerr << "Erro: a variável '" << name << "' ja foi declarada na linha " << current[name].ln << "." << endl;
    exit(1);     
}

vector<string> declareVariable(Decl type, string name, int ln, int col) {
    Attributes attr = {vec(name), 0, {}, ln, col};
    return declareVariable(type, attr);
}

void verifyAttrib(string name, bool a) {
    /* cout << "Verificando atribuição" << endl;
    cout << "Nome: " << name << endl; */

    for (int i = symbols.size() - 1; i >=0; i--){
        auto& curr = symbols[i];
        /* cout << " ==== escopo nivel " << i << " ====" << endl; */
        /* for (const auto& pair : symbols[i]) {
            cout << "Key: " << pair.first << endl;
            cout << "Ln: " << pair.second.ln << endl;
            cout << "Col: " << pair.second.col << endl;
            cout << "Type: " << pair.second.type << endl;
            cout << "====================" << endl;
        }
        cout << "curr.count(name): " << curr.count(name) << endl; */
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

vector<string> declareFunction( Attributes attr ) {
    /* cout << "Declarando função" << endl; */
    return declareVariable( DeclVar, attr );
    /* cout << "Retorno: " << r[0] << ";" << r[1] << endl; */
    /* return r; */
}

tuple<string,string,string,string> generateIfLabels(){
    string lbl_true = getLabel( "lbl_true" );
    string lbl_end_if = getLabel( "lbl_end_if" );
    string def_lbl_true = ":" + lbl_true;
    string def_lbl_end_if = ":" + lbl_end_if;
    return make_tuple(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if);
}

vector<string> generateParamsCode(Attributes attr){
    string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
    tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
    return declareVariable(DeclVar, "df_name", 1, 1) +
        attr.code + "@" + "df_name" + "@" + "==" +
        lbl_true + "?" + lbl_end_if + "#" + 
        def_lbl_true + attr.code + attr.default_value + "=" + "^" +
        def_lbl_end_if;
}

string trim(string str, string charsToTrim){
	for(auto c : charsToTrim){
		str.erase(remove(str.begin(), str.end(), c), str.end());
	}
	return str;
}

vector<string> getFormattedMdpCode(string mdpCode){
	vector<string> formattedMdp;
	string instr = "";
	for(auto c : mdpCode){
		if(c != ' ')
			instr = instr + c;
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
