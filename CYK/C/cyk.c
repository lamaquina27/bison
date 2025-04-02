#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_N 100
#define MAX_STRING 100

typedef struct {
    char* elements[MAX_N];
    int size;
} Set;

const char* numerals[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void add_to_set(Set* set, const char* element) {
    if (set->size < MAX_N) {
        set->elements[set->size] = strdup(element);
        set->size++;
    }
}

int contains(Set* set, const char* element) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->elements[i], element) == 0) {
            return 1;
        }
    }
    return 0;
}

int cyk(const char* comienzo, const char* string) {
    int n = strlen(string);
    if (n == 0) return 0;

    Set table[MAX_N][MAX_N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j].size = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (string[i] == numerals[j][0]) {
                add_to_set(&table[i][i], "NUM");
            }
        }
        if (strchr("+-*/()", string[i])) {
            add_to_set(&table[i][i], "OP");
        }
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            for (int k = i; k < j; k++) {
                if (contains(&table[i][k], "E") && contains(&table[k+1][j], "T")) {
                    add_to_set(&table[i][j], "E");
                }
                if (contains(&table[i][k], "T") && contains(&table[k+1][j], "F")) {
                    add_to_set(&table[i][j], "T");
                }
                if (contains(&table[i][k], "F") && contains(&table[k+1][j], "NUM")) {
                    add_to_set(&table[i][j], "F");
                }
            }
        }
    }

    return contains(&table[0][n-1], comienzo);
}

int main() {
    char* ejemplos[] = {"3+5", "7-2*3", "(4+5)*2", "10/2+3", "8*(3+2)-4"};
    int num_ejemplos = 5;

    clock_t start_time, end_time;
    double tiempo_ejecucion[num_ejemplos];
    FILE *file = fopen("tiempos_cyk.txt", "w");

    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    for (int i = 0; i < num_ejemplos; i++) {
        start_time = clock();
        int resultado = cyk("E", ejemplos[i]);
        end_time = clock();
        tiempo_ejecucion[i] = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

        fprintf(file, "%d %.4f\n", i+1, tiempo_ejecucion[i]);
        printf("Resultado para '%s': %s\n", ejemplos[i], resultado ? "Sí" : "No");
    }
    fclose(file);

    FILE* gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Tiempos de Ejecución'\n");
        fprintf(gnuplot, "set xlabel 'Ejemplo'\n");
        fprintf(gnuplot, "set ylabel 'Tiempo (ms)'\n");
        fprintf(gnuplot, "plot 'tiempos_cyk.txt' using 1:2 with linespoints title 'CYK'\n");
        pclose(gnuplot);
    }

    return 0;
}
