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
        printf("\nEstudiante %d", i + 1);
        printf("\nPromedio: %.2f", suma / MATERIAS);
        printf("\nNota mas alta: %.2f", mayor);
        printf("\nNota mas baja: %.2f\n", menor);
    }
    for(int j = 0; j < MATERIAS; j++) {
        float suma = 0, mayor = e[0].notas[j], menor = e[0].notas[j];
        int aprobados = 0, reprobados = 0;

        for(int i = 0; i < n; i++) {
            float nota = e[i].notas[j];

            suma += nota;

            if(nota > mayor)
                mayor = nota;

            if(nota < menor)
                menor = nota;

            if(nota >= 6)
                aprobados++;
            else
                reprobados++;
        }

        printf("\nMateria %d", j + 1);
        printf("\nPromedio: %.2f", suma / n);
        printf("\nNota mas alta: %.2f", mayor);
        printf("\nNota mas baja: %.2f", menor);
        printf("\nAprobados: %d", aprobados);
        printf("\nReprobados: %d\n", reprobados);
    }
}