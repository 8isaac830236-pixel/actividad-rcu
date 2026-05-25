#include <stdio.h>
#include <stdlib.h>

float** asignarMemoria(int estudiantes, int asignaturas);
void leerNotas(float** notas, int n, int m);
void reporteEstudiantes(float** notas, int n, int m); // Nuevo prototipo para el Commit 3
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
    
    leerNotas(notas, n, ASIG);
    
    // Llamada al reporte de estudiantes (Commit 3)
    reporteEstudiantes(notas, n, ASIG);
    
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

// Nueva funcion para calcular promedios, maximos y minimos por alumno usando punteros
void reporteEstudiantes(float** notas, int n, int m) {
    printf("\n--- REPORTE POR ESTUDIANTE ---\n");
    for (int i = 0; i < n; i++) {
        float suma = 0;
        float max = *(*(notas + i) + 0);
        float min = *(*(notas + i) + 0);
        
        for (int j = 0; j < m; j++) {
            float val = *(*(notas + i) + j);
            suma += val;
            if (val > max) max = val;
            if (val < min) min = val;
        }
        printf("Est. %d | Promedio: %.2f | Maxima: %.2f | Minima: %.2f\n", i + 1, suma / m, max, min);
    }
}

void liberarMemoria(float** notas, int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        free(*(notas + i));
    }
    free(notas);
}