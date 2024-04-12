%{
#include <iostream>
using namespace std;
string lexema;
//enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
FLUTUANTE   {DIGITO}+((\.{DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
ID          ($|{LETRA})({LETRA}|{DIGITO})*
WS          [ \n\r\t]+

%%

{WS}    { }

"if"    { lexema = yytext; return _IF; }

"for"   { lexema = yytext; return _FOR; }

{ID}    { lexema = yytext; return _ID; }

{INTEIRO}   { lexema = yytext; return _INT; }

{FLUTUANTE} { lexema = yytext; return _FLOAT; }

.       { lexema = yytext; return yytext[0]; }

%%