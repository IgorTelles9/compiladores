%{
#include <iostream>
using namespace std;
string lexema;
//enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

void identifierError(string s){
    cout << "Erro: Identificador invalido: " << s << endl; 
}

%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
FLUTUANTE   {DIGITO}+((\.{DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
ID          ($|{LETRA})({LETRA}|{DIGITO})*
ERRO_ID     {ID}($)+
WS          [ \n\r\t]+

%%

{WS}    { }

">="    { lexema = yytext; return _MAIG; }

"<="    { lexema = yytext; return _MEIG; }

"=="    { lexema = yytext; return _IG; }

"!="    { lexema = yytext; return _DIF; }

"if"    { lexema = yytext; return _IF; }

"for"   { lexema = yytext; return _FOR; }

{INTEIRO}   { lexema = yytext; return _INT; }

{FLUTUANTE} { lexema = yytext; return _FLOAT; }

{ID}    { lexema = yytext; return _ID; }

{ERRO_ID}   { lexema = yytext; identifierError(lexema);  }

.       { lexema = yytext; return yytext[0]; }

%%