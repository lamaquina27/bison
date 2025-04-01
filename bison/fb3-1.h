/*
* Declarations for a calculator fb3-1
*/


#include <stdarg.h>

/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
/* nodes in the abstract syntax tree */
struct ast {
int nodetype;
struct ast *l;
struct ast *r;
};
struct numval {
int nodetype;
double number;
};
/* type K for constant */
/* build an AST */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);
/* evaluate an AST */
double eval(struct ast *);
/* delete and free an AST */
void treefree(struct ast *);