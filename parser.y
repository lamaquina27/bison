%{
    #include <stdio.h>
    void yyerror(const char *s);
    int yylex(void);
%}

%token a b

%%
S : A B
  | B C
  ;

A : C B
  | a
  ;

B : C C
  | b
  ;

C : B
  | a
  ;

%%
