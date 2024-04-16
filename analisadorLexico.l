%{
#include <iostream>
using namespace std;
string lexema;
// enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

void identifierError(string s){
    cout << "Erro: Identificador invalido: " << s << endl; 
}

string splitString(string s, int size){
    return s.substr(1,s.length()-size);
}

string stringFormatter(string t, bool singleQuotes){
    string s = splitString(t,2);
    string r = "";
    for (int i = 0; i < s.length(); i++){
        // identify escaped quotes
        if (
            (s[i] == '\\' && (s[i+1] == '\"' || s[i+1] == '\''))    // escaped using backslash
            || ( singleQuotes && s[i] == '\'' && s[i+1] == '\'')    // escaped using double single quotes
            || ( !singleQuotes && s[i] == '\"' && s[i+1] == '\"')    // escaped using double double quotes
        ){
            i++;
        }            
        r = r + s[i]; 
    }
    return r;
}
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
FLUTUANTE   {DIGITO}+((\.{DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
STRING_11   \"([^"]|\"\"|\\.)*\"
STRING_12   \'([^']|\'\'|\\.)*\'
STRING_2_FULL    \`([^`{}])*\`
STRING_2_BEGIN  \`(.*)\$
STRING_2_EXPR   \{(.*)
STRING_2_END    \}([^}]*?)`
COMENTARIO_1   \/\*\s*([^*]*\*[^\/]*)\\*\/ 
COMENTARIO_2   [/][/].*
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

{STRING_11} { lexema = stringFormatter(yytext, false); return _STRING; }

{STRING_12} { lexema = stringFormatter(yytext, true); return _STRING; }

{STRING_2_FULL}  { lexema = stringFormatter(yytext, false); return _STRING2; }

{STRING_2_BEGIN} { lexema = splitString(yytext,2); return _STRING2; }
{STRING_2_EXPR}/"}"    { lexema = splitString(yytext,1); return _EXPR; }
{STRING_2_END}    { lexema = splitString(yytext,2); return _STRING2; }

{COMENTARIO_1}  { lexema = yytext; return _COMENTARIO; }
{COMENTARIO_2}  { lexema = yytext; return _COMENTARIO; }

{INTEIRO}   { lexema = yytext; return _INT; }

{FLUTUANTE} { lexema = yytext; return _FLOAT; }

{ID}    { lexema = yytext; return _ID; }

{ERRO_ID}   { lexema = yytext; identifierError(lexema);  }

.       { lexema = yytext; return yytext[0]; }

%%