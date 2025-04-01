#include <stdio.h>
#include <stdlib.h>
#include "fb3-1.h"
#include "fb3-1.tab.h"

/* Construcción del AST */
struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
  struct ast *a = malloc(sizeof(struct ast));
  if(!a) {
    yyerror("Sin memoria");
    exit(1);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}

struct ast *newnum(double d) {
  struct numval *a = malloc(sizeof(struct numval));
  if(!a) {
    yyerror("Sin memoria");
    exit(1);
  }
  a->nodetype = 'K';
  a->number = d;
  return (struct ast *)a;
}

/* Evaluación del AST */
double eval(struct ast *a) {
  switch(a->nodetype) {
    case 'K': return ((struct numval *)a)->number;
    case '+': return eval(a->l) + eval(a->r);
    case '-': return eval(a->l) - eval(a->r);
    case '*': return eval(a->l) * eval(a->r);
    case '/': return eval(a->l) / eval(a->r);
    case 'M': return -eval(a->l);
    default: yyerror("Nodo desconocido %c\n", a->nodetype);
  }
  return 0.0;
}

/* Liberación de memoria */
void treefree(struct ast *a) {
  if (!a) return;
  if (a->nodetype != 'K') {
    treefree(a->l);
    treefree(a->r);
  }
  free(a);
}


void yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);
  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int main(){
  printf("> ");
  return yyparse();
}
