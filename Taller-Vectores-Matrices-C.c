#include <stdio.h>

int main() {
    float notas[5][3];
    float suma;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            do {
                printf("Estudiante %d, Asignatura %d (0-10): ", i+1, j+1);
                scanf("%f", &notas[i][j]);
            } while(notas[i][j] < 0 || notas[i][j] > 10); // Validación [cite: 20]
        }
    }
    
    return 0;
}