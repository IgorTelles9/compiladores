%{
#include <iostream>

using namespace std;

string lexema;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

%}
D           [0-9]
L           [a-zA-Z_]
NUM         {D}+(\.{D}+)?([Ee][+\-]?{D}+)?
ID          {L}({L}|{D})*
WS          [ \n\r\t]+

%%

{WS}    { }

{ID}    { lexema = yytext; return _ID; }

.       { lexema = yytext; return yytext[0]; }

%%