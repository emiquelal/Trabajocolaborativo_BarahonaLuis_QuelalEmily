#include <stdio.h>

#define MATERIAS 3
#define MAX_ESTUDIANTES 50

typedef struct {
    float notas[MATERIAS];
} Estudiante;

void ingresarNotas(Estudiante *e, int n);
void mostrarResultados(Estudiante *e, int n);
int main() {
    int n;
    Estudiante e[MAX_ESTUDIANTES];

    printf("Numero de estudiantes: ");
    scanf("%d", &n);

    ingresarNotas(e, n);
    mostrarResultados(e, n);

    return 0;
}

void ingresarNotas(Estudiante *e, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEstudiante %d\n", i + 1);

        for(int j = 0; j < MATERIAS; j++) {
            do {
                printf("Nota materia %d (0-10): ", j + 1);
                scanf("%f", &e[i].notas[j]);
            } while(e[i].notas[j] < 0 || e[i].notas[j] > 10);
        }
    }
}
void mostrarResultados(Estudiante *e, int n) {
    for(int i = 0; i < n; i++) {
        float suma = 0, mayor = e[i].notas[0], menor = e[i].notas[0];

        for(int j = 0; j < MATERIAS; j++) {
            suma += e[i].notas[j];

            if(e[i].notas[j] > mayor)
                mayor = e[i].notas[j];

            if(e[i].notas[j] < menor)
                menor = e[i].notas[j];
        }
    }
