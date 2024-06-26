%{
void updateAttributes();
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
FLUTUANTE   {DIGITO}+((\.{DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
STRING      (\"([^\"\n]*)\")|{STRING_ESC}  
STRING_ESC  [\"][^\"]*([\\]|[\"])[\"][^\"]*[\"]
STRING_2     (\'([^\'\n]*)\')|{STRING_ESC_2}  
STRING_ESC_2 [\'][^\']*([\\]|[\'])[\'][^\']*[\']
ID          ($|{LETRA})({LETRA}|{DIGITO})*
WS          [ \n\r\t]+

%%
"\t"        { col += 4;                             }
" "         { col += 1;                             }
"\n"        { col = 1; ln += 1;                     }
"&&"        { updateAttributes(); return AND;       }
"||"        { updateAttributes(); return OR;        }
"=="        { updateAttributes(); return EQUAL;     }
">="        { updateAttributes(); return GT_EQ;     }
"<="        { updateAttributes(); return LT_EQ;     }
"!="        { updateAttributes(); return DIFF;      }
"+="        { updateAttributes(); return PLUS_EQ;   }
"++"        { updateAttributes(); return PLUS_PLUS; }
"{}"        { updateAttributes(); return OBJ;       }
"[]"        { updateAttributes(); return ARRAY;     }
"if"        { updateAttributes(); return IF;        }
"else"      { updateAttributes(); return ELSE;      }
"for"       { updateAttributes(); return FOR;       }
"while"     { updateAttributes(); return WHILE;     }
"let"       { updateAttributes(); return LET;       }
"const"     { updateAttributes(); return CONST;     }
"var"       { updateAttributes(); return VAR;       }
"print"     { updateAttributes(); return PRINT;     }
{STRING}    { updateAttributes(); return STRING;    }
{STRING_2}  { updateAttributes(); return STRING;    }
{INTEIRO}   { updateAttributes(); return INT;       }
{FLUTUANTE} { updateAttributes(); return FLOAT;     }
{ID}        { updateAttributes(); return ID;        }
{WS}        {                                       } 
.           { updateAttributes(); return yytext[0]; }

%%

void updateAttributes() {  
  yylval.code = vector<string>{ yytext };
  col += strlen( yytext ); 
  yylval.ln = ln;
  yylval.col = col;

}