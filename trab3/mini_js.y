%{
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int ln = 1, col = 0; 

struct Attributes {
    vector<string> code; 

    int ln = 0, col = 0;

    void clear() {
        code.clear();
        ln = 0;
        col = 0;
    }
};

#define YYSTYPE Attributes

enum Decl { DeclVar=1, DeclConst, DeclLet };

struct Variable {
  int ln, col;
  Decl type;
};

map<string,Variable> symbols; 

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

vector<string> concat(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> resolveAddr(vector<string> code);
string getLabel(string prefix);
void print(vector<string> code);
vector<string> declareVariable(Decl type, Attributes attr);
void verifyAttrib(string name);
vector<string> vec(string s);

%}

%token AND OR EQUAL GT_EQ LT_EQ DIFF PLUS_EQ PLUS_PLUS
%token OBJ ARRAY IF ELSE FOR WHILE LET CONST VAR
%token PRINT STRING INT FLOAT ID

%right '='
%nonassoc '<' '>'
%left '+' '-'
%left '*' '/' '%'

%left '['
%left '.'

%%
S : CMDs { print(resolveAddr($1.code  + ".")); }
    ;

CMDs : CMDs CMD { $$.code = $1.code + $2.code; }
     | {$$.clear();}
     ;

CMD : DECL_LET
    | DECL_CONST
    | DECL_VAR
    | E ';' { $$.code = $1.code + "^";}
    ;
    
DECL_LET : LET LET_IDs ';' { $$ = $2; }
         ;
         
LET_IDs : LET_ID ',' LET_IDs { $$.code = $1.code + $3.code; }
        | LET_ID
        ;

LET_ID : ID { declareVariable(DeclLet, $1); $$.code = $1.code + "&"; }
       | ID '=' E { declareVariable(DeclLet, $1); $$.code = $1.code + "&" + $1.code + $3.code + "=" + "^"; }
       ;

DECL_CONST : CONST CONST_IDs ';' { $$ = $2; }
         ;

CONST_IDs : CONST_ID ',' CONST_IDs { $$.code = $1.code + $3.code; }
        | CONST_ID
        ;

CONST_ID : ID { declareVariable(DeclConst, $1); $$.code = $1.code + "&"; }
       | ID '=' E { declareVariable(DeclConst, $1); $$.code = $1.code + "&" + $1.code + $3.code + "=" + "^"; }
       ;

DECL_VAR : VAR VAR_IDs ';' { $$ = $2; }
         ;

VAR_IDs : VAR_ID ',' VAR_IDs { $$.code = $1.code + $3.code; }
        | VAR_ID
        ;

VAR_ID : ID { declareVariable(DeclVar, $1); $$.code = $1.code + "&"; }
       | ID '=' E { declareVariable(DeclVar, $1); $$.code = $1.code + "&" + $1.code + $3.code + "=" + "^"; }
       ;

E : LVALUE '=' E { verifyAttrib($1.code[0]); $$.code = $1.code + $3.code + "="; }
    | LVALUE PLUS_EQ E { verifyAttrib($1.code[0]); $$.code = $1.code + $1.code + "@" + $3.code + "+" + "="; }
    | LVALUEPROP '=' E 	{ $$.code = $1.code + $3.code + "[=]"; }
    | E '<' E { $$.code = $1.code + $3.code + "<"; }
    | E '>' E { $$.code = $1.code + $3.code + ">"; }
    | E '+' E { $$.code = $1.code + $3.code + "+"; }
    | E '*' E { $$.code = $1.code + $3.code + "*"; }
    | E '/' E { $$.code = $1.code + $3.code + "/"; }
    | E '-' E { $$.code = $1.code + $3.code + "-"; }
    | E '%' E { $$.code = $1.code + $3.code + "%"; }
    | '-' E   {$$.code = "0" + $2.code + $1.code; }
    | ARRAY   { $$.code = vec("[]"); } 
    | OBJ     { $$.code = vec("{}"); } 
    | FLOAT
    | INT
    | STRING
    | LVALUE 	    { $$.code = $1.code + "@"; }
    | LVALUEPROP    { $$.code = $1.code + "[@]"; }
    | '(' E ')'     { $$.code = $2.code; }

LVALUE  :   ID 
        ; 

LVALUEPROP  :   E '.' ID { $$.code = $1.code + $3.code; }
            |   E '[' E ']' { $$.code = $1.code + $3.code; }
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
    string name = attr.code[0];
    int ln = attr.ln, col = attr.col;
    if(symbols.count(name) == 0) {
        symbols[name] = Variable{ln, col, type};
        return vector<string>{name, "&"};
    }
    if(type == DeclVar && symbols[name].type == DeclVar ) {
        symbols[name] = Variable{ln, col, type};
        return vector<string>{};
    } 
    cerr << "Erro: a variável '" << name << "' ja foi declarada na linha " << symbols[name].ln << "." << endl;
    exit(1);     
}

void verifyAttrib(string name) {
    if(symbols.count(name) > 0) {
        if(symbols[name].type == DeclConst) {
            cerr << "Erro: a variável '" << name << "' não pode ser modificada." << endl;
            exit(1);     
        }
    } else {
        cerr << "Erro: a variável '" << name << "' não foi declarada." << endl;
        exit(1);     
    }
}

vector<string> vec(string s) {
    return vector<string>{s};
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
