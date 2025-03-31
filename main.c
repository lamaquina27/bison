#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "parser.tab.h"  // Incluir el archivo de Bison

extern int yylex();  // Declarar la función de Flex
extern int yyparse(); // Declarar la función de Bison
extern FILE *yyin;   // Archivo de entrada para Flex

// Manejo de errores en Bison
void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int main() {
    char *ejemplos[] = {"ab", "ba", "aaa", "bba", "aaaab"};
    FILE *file = fopen("tiempos.dat", "w");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Probando: %s\n", ejemplos[i]);
        yyin = fmemopen(ejemplos[i], strlen(ejemplos[i]), "r");
        
        clock_t inicio = clock();
        int resultado = yyparse();
        clock_t fin = clock();
        
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        fprintf(file, "%d %f\n", i + 1, tiempo);
        
        if (resultado == 0) {
            printf("Cadena aceptada.\n");
        } else {
            printf("Error en el análisis.\n");
        }
        fclose(yyin);
    }
    
    fclose(file);
    printf("Datos guardados en tiempos.dat\n");
    return 0;
}
