#include <stdio.h>
#include <stdlib.h>

float** asignarMemoria(int estudiantes, int asignaturas);
void liberarMemoria(float** notas, int estudiantes);

int main() {
    int n;
    const int ASIG = 3; 

    printf("Gestion de Calificaciones Escolares\n");
    printf("----------------------------------\n");
    printf("Ingrese el numero de estudiantes: ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Numero de estudiantes no valido.\n");
        return 1;
    }

    float** notas = asignarMemoria(n, ASIG);
    
    liberarMemoria(notas, n);
    return 0;
}

float** asignarMemoria(int estudiantes, int asignaturas) {
    float** matriz = (float**)malloc(estudiantes * sizeof(float*));
    for (int i = 0; i < estudiantes; i++) {
        *(matriz + i) = (float*)malloc(asignaturas * sizeof(float));
    }
    return matriz;
}

void liberarMemoria(float** notas, int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        free(*(notas + i));
    }
    free(notas);
}