%{
void updateAttributes();
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
INTEIRO     {DIGITO}+
BOOL        (true|false)
FLUTUANTE   {DIGITO}+\.(({DIGITO}+)?([Ee][+\-]?{DIGITO}+)?)+
STRING      (\"([^\"\n]*)\")|{STRING_ESC}  
STRING_ESC  [\"][^\"]*([\\]|[\"])[\"][^\"]*[\"]
STRING_2     (\'([^\'\n]*)\')|{STRING_ESC_2}  
STRING_ESC_2 [\'][^\']*([\\]|[\'])[\'][^\']*[\']
ID          ($|{LETRA})({LETRA}|{DIGITO})*
EMPTY_BLOCK \{\s*\}

%%
{EMPTY_BLOCK}   { updateAttributes(); return EMPTY_BLOCK;      }
"\t"            { col += 4;                                    }
" "             { col += 1;                                    }
"\n"            { col = 1; ln +=1;                             }
"&&"            { updateAttributes(); return AND;              }
"||"            { updateAttributes(); return OR;               }
"=>"            { updateAttributes(); return ARROW;            }
"<="            { updateAttributes(); return LT_EQ;            }
">="            { updateAttributes(); return GT_EQ;            }
"!="            { updateAttributes(); return DIFF;             }
"=="            { updateAttributes(); return EQUAL;            }
"+="            { updateAttributes(); return PLUS_EQ;          }
"++"            { updateAttributes(); return PLUS_PLUS;        }
"if"            { updateAttributes(); return IF;               }
"else"          { updateAttributes(); return ELSE;             }
"for"           { updateAttributes(); return FOR;              }
"while"         { updateAttributes(); return WHILE;            }
"let"           { updateAttributes(); return LET;              }
"const"         { updateAttributes(); return CONST;            }
"return"        { updateAttributes(); return RETURN;           }
"var"           { updateAttributes(); return VAR;              }
"function"      { updateAttributes(); return FUNCTION;         }
")"/.*"=>"      { updateAttributes(); return PARENTESIS_ARROW; }
"=> {"          { updateAttributes(); return ARROW_OBJ;        }
"asm{".*"}"     {  
                    string mdp = trim( yytext + 3, "{}" ); 
                    yylval.code = getFormattedMdpCode( mdp );
                    col += strlen( yytext ); 
                    return ASM; 
                }
{BOOL}      { updateAttributes(); return BOOL;      }
{INTEIRO}   { updateAttributes(); return INT;       }
{FLUTUANTE} { updateAttributes(); return FLOAT;     }
{STRING}    { updateAttributes(); return STRING;    }
{STRING_2}  { updateAttributes(); return STRING;    }
{ID}        { updateAttributes(); return ID;        }
.           { updateAttributes(); return yytext[0]; }

%%

void updateAttributes() {  
  yylval.code = vector<string>{ yytext };
  col += strlen( yytext ); 
  yylval.ln = ln;
  yylval.col = col;

}