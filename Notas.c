#include <stdio.h>

#define MATERIAS 3
#define MAX_ESTUDIANTES 50

typedef struct {
    float notas[MATERIAS];
} Estudiante;

void ingresarNotas(Estudiante *e, int n);
void mostrarResultados(Estudiante *e, int n);
