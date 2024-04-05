#main.c#
#include <stdlib.h>
#include <stdio.h>
#include "oper.h"

int main() {
    int n;
    printf("Vvedite razmernost matrici: ");
    scanf("%d", &n);
    
    int** mA = (int**)malloc(n * sizeof(int*));
    int** mB = (int**)malloc(n * sizeof(int*));
    
    printf("Vvedite elementi martici A:\n");
    for (int i = 0; i < n; i++) {
        mA[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &mA[i][j]);
        }
    }
    
    printf("Vvedite elementi martici B:\n");
    for (int i = 0; i < n; i++) {
        mB[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &mB[i][j]);
        }
    }
    
    char operation;
    printf("Vibirite operation (+, -, *): ");
    scanf(" %c", &operation);
    
    int** result = oper(mA, mB, n, operation);
    
    printf("Rezultat:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(mA[i]);
        free(mB[i]);
        free(result[i]);
    }
    free(mA);
    free(mB);
    free(result);
    
    return 0;
}


#oper.h#
int** oper(int** mA, int** mB, int n, char operation);
