%{
#include "parser.tab.h"
#include <stdio.h>
%}

%%
a    { printf("TOKEN: a\n"); return a; }
b    { printf("TOKEN: b\n"); return b; }
[ \t\n]+  ;  // Ignorar espacios y saltos de línea
.    { printf("TOKEN NO RECONOCIDO: %s\n", yytext); return yytext[0]; }
%%

int yywrap() { return 1; }
