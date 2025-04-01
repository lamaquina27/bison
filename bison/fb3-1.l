%option noyywrap nodefault yylineno
%{
# include "fb3-1.h"
# include "fb3-1.tab.h"
%}
%%
"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")"     { return yytext[0]; }
[0-9]+"."[0-9]* |
"."?[0-9]+ { yylval.d = atof(yytext); return NUMBER; }

\n { return EOL; }
"//".*  /* Ignora comentarios */
[ \t]   /* Ignora espacios */
. { yyerror("Caracter desconocido %c\n", *yytext); }





%%
