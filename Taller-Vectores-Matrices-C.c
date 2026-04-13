#include <stdio.h>

int main() {
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    int aprobados;

    for (int i = 0; i < 5; i++) {
        printf("--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf("Asignatura %d: ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: La nota debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    printf("\n--- Promedio por Estudiante ---\n");
    for (int i = 0; i < 5; i++) {
        sumaEstudiante = 0;
        float maxEst = notas[i][0], minEst = notas[i][0];
        for (int j = 0; j < 3; j++) {
            sumaEstudiante += notas[i][j];
            if (notas[i][j] > maxEst) maxEst = notas[i][j];
            if (notas[i][j] < minEst) minEst = notas[i][j];
        }
        printf("Estudiante %d: %.2f (Max: %.2f, Min: %.2f)\n", i + 1, sumaEstudiante / 3, maxEst, minEst);
    }

    printf("\n--- Reporte por Asignatura ---\n");
    for (int j = 0; j < 3; j++) {
        sumaAsignatura = 0;
        aprobados = 0;
        float maxAsig = notas[0][j], minAsig = notas[0][j];
        
        for (int i = 0; i < 5; i++) {
            sumaAsignatura += notas[i][j];
            // Nota aprobatoria >= 6 [cite: 28]
            if (notas[i][j] >= 6) aprobados++;
            if (notas[i][j] > maxAsig) maxAsig = notas[i][j];
            if (notas[i][j] < minAsig) minAsig = notas[i][j];
        }
        printf("Asignatura %d: Promedio %.2f, Aprobados: %d, Reprobados: %d\n", 
                j + 1, sumaAsignatura / 5, aprobados, 5 - aprobados);
        printf("   (Nota mas alta: %.2f, mas baja: %.2f)\n", maxAsig, minAsig);
    }

    return 0;
}