%{
#include <iostream> 
#include <string>

using namespace std;
enum TOKEN { ID = 256, NUM, MAIOR_IGUAL, MENOR_IGUAL, IGUAL,  };

string lexema;

%}

D	[0-9]
L 	[a-zA-Z_]
ID	{L}({L}|{D})*
NUM {D}+(\.{D}+)?([Ee][+\-]?{D}+)? 
WS	[ \n\r\t]+
%%
{WS}	{ }

{NUM}	{ lexema = yytext; return NUM; }
{ID}	{ lexema = yytext; return ID; }
.	{ lexema - yytext; return }

%%

int main () {
	int token = yylex();
	while (token != 0){
		cout << "Valor: " << token << ", lexema: " << lexema << endl;
		token = yylex();
	}
	
	return 0;
}
