#include <stdio.h>
#include <stdlib.h>

float** asignarMemoria(int estudiantes, int asignaturas);
void leerNotas(float** notas, int n, int m); // Nuevo prototipo
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
    
    // Llamada a la funcion de lectura (Commit 2)
    leerNotas(notas, n, ASIG);
    
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

// Nueva funcion para leer y validar notas usando punteros
void leerNotas(float** notas, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("\nNotas del Estudiante %d:\n", i + 1);
        for (int j = 0; j < m; j++) {
            do {
                printf("  Asignatura %d [0-10]: ", j + 1);
                scanf("%f", (*(notas + i) + j));
            } while (*(*(notas + i) + j) < 0 || *(*(notas + i) + j) > 10);
        }
    }
}

void liberarMemoria(float** notas, int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        free(*(notas + i));
    }
    free(notas);
}