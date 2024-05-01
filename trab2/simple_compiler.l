%{
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string lexema;
int token;

int nextToken();
void match(int);
string getTokenName(int);

void START();
void A();
void E();
void E_LINHA();
void T();
void T_LINHA();
void U();
void W();
void FAT();
void POT();
void F();
void P();
void P_LINHA();



enum { ID = 256, INT, PRINT, FLOAT, STRING, FUNCTION };

map<int,string> tokenNames;

%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
FLUTUANTE   {DIGITO}+((\.{DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
STRING      (\"([^\"\n]*)\")|{STRING_ESC}  
STRING_ESC  [\"][^\"]*([\\]|[\"])[\"][^\"]*[\"]
ID          ($|{LETRA})({LETRA}|{DIGITO})*
ERRO_ID     {ID}($)+
WS          [ \n\r\t]+

%%

{WS}        {                                   }
"print"     { lexema = yytext; return PRINT;    }
{STRING}    { lexema = yytext; return STRING;   }
{INTEIRO}   { lexema = yytext; return INT;      }
{FLUTUANTE} { lexema = yytext; return FLOAT;    }
{ID}        { lexema = yytext; return ID;       }
{ID}/"("    { lexema = yytext; return FUNCTION; }
.           { lexema = yytext; return yytext[0];}

%%

// ====== Grammar Rules functions ========

int nextToken() {
    return yylex();
}

string getTokenName(int token) {
    if(tokenNames.find(token) != tokenNames.end())
        return tokenNames[token];
    else {
        string r;
        r = token;
        return r;
    }
}

void match(int expected) {
    if(token == expected)
        token = nextToken();
    else {
        cout << "Erro: era esperado " << getTokenName(expected) << " mas foi encontrado " << getTokenName(token) << endl;
        exit(1);
    }
}

void START(){
    A();
    if(token == ';') {
        match(';');
        START();
    }
}

void A(){
    switch (token){
        case PRINT:
            match(PRINT);
            E();
            cout << "print # ";
            break;
        case ID:
            cout << lexema << " ";
            match(ID);
            match('=');
            E();
            cout << " = ^ ";
            break;
    }
}

void E(){
    T();
    E_LINHA();
}

void E_LINHA(){
    switch (token){
        case '+':
            match('+');
            T();
            cout << "+ ";
            E_LINHA();
            break;
        case '-':
            match('-');
            T();
            cout << "- ";
            E_LINHA();
            break;
    }
}

void T(){
    U();
    T_LINHA();
}

void T_LINHA(){
    switch (token){
        case '*':
            match('*');
            U();
            cout << "* ";
            T_LINHA();
            break;
        case '/':
            match('/');
            U();
            cout << "/ ";
            T_LINHA();
            break;
    }
}

void U(){
    switch (token){
        case '-':
            cout << 0 << " ";
            match('-');
            U();
            cout << "- ";
            break;
        case '+':
            match('+');
            U();
            cout << "+ ";
            break;
        default: W();
    }
}

void W(){
    F();
    FAT();
    POT();
}

void FAT(){
    if (token == '!'){
        match('!');
        W();
        cout << "fat # ";
    }
}

void POT(){
    if (token == '^'){
        match('^');
        W();
        cout << "power # ";
    }
}

void F(){
    string temp = lexema;
    switch (token){
        case ID:
            cout << lexema << " @ ";
            match(ID);
            break;

        case INT:
            cout << lexema << " ";
            match(INT);
            break;

        case FLOAT:
            cout << lexema << " ";
            match(FLOAT);
            break;

        case STRING:
            cout << lexema << " ";
            match(STRING);
            break;

        case FUNCTION:
            match(FUNCTION);
            match('(');
            P();
            match(')');
            cout << temp << " # ";
            break;

        case '(':
            match('(');
            E();
            match(')');
            break;
    }

}

void P(){
    E();
    P_LINHA();
}

void P_LINHA(){
    if (token == ','){
        match(',');
        E();
        P_LINHA();
    }
}

int main() {
  tokenNames[INT] = "int";
  tokenNames[FLOAT] = "float"; 
  tokenNames[STRING] = "string";
  tokenNames[ID] = "nome de identificador";
  tokenNames[PRINT] = "print";
  tokenNames[FUNCTION] = "function";

  token = nextToken();
  START();
  
//   if( token == 0 )
//     cout << "Sintaxe ok!" << endl;
//   else
//     cout << "Caracteres encontrados após o final do programa" << endl;
  
  return 0;
}