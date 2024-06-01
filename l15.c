#include <stdio.h>

void printDigits(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }

    printDigits(n / 10);
    printf("%d ", n % 10);
}

void printDigitsReverse(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }

    printf("%d ", n % 10);
    printDigitsReverse(n / 10);
}

int main() {
    int N;

    printf("Введите натуральное число: ");
    scanf("%d", &N);

    printf("Цифры в обычном порядке: ", N);
    printDigits(N);
    
    printf("\nЦифры в обратном порядке: ", N);
    printDigitsReverse(N);

    return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // заполнение случайными числами от 0 до 9
        }
    }
}

void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int** result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void addMatrices(int** matrix1, int** matrix2, int rows, int cols, int** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    srand(time(0));

    int** matrix1 = createMatrix(rows, cols);
    int** matrix2 = createMatrix(rows, cols);
    int** resultMatrix = createMatrix(rows, cols);

    fillMatrix(matrix1, rows, cols);
    fillMatrix(matrix2, rows, cols);

    clock_t start = clock();

    multiplyMatrices(matrix1, rows, cols, matrix2, rows, cols, resultMatrix);
    addMatrices(matrix1, matrix2, rows, cols, resultMatrix);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка при создании файла output.txt\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(outputFile, "%d ", resultMatrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    printf("Результаты записаны в файл output.txt\n");
    printf("Время выполнения программы: %.3f секунд\n", seconds);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}









Конечно, разделим данный код на модули для более удобного и структурированного восприятия. Вот как это можно сделать:

Matrix.c:

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // заполнение случайными числами от 0 до 9
        }
    }
}

void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int** result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void addMatrices(int** matrix1, int** matrix2, int rows, int cols, int** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


Matrix.h:

#ifndef MATRIX_H
#define MATRIX_H

int** createMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);
void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int** result);
void addMatrices(int** matrix1, int** matrix2, int rows, int cols, int** result);

#endif /* MATRIX_H */


Main.c:

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include <time.h>

int main() {
    int rows, cols;
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    srand(time(0));

    int** matrix1 = createMatrix(rows, cols);
    int** matrix2 = createMatrix(rows, cols);
    int** resultMatrix = createMatrix(rows, cols);

    fillMatrix(matrix1, rows, cols);
    fillMatrix(matrix2, rows, cols);

    clock_t start = clock();

    multiplyMatrices(matrix1, rows, cols, matrix2, rows, cols, resultMatrix);
    addMatrices(matrix1, matrix2, rows, cols, resultMatrix);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка при создании файла output.txt\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(outputFile, "%d ", resultMatrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    printf("Результаты записаны в файл output.txt\n");
    printf("Время выполнения программы: %.3f секунд\n", seconds);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}


Теперь у нас есть отдельные модули для операций над матрицами (Matrix.c) и для функции main (Main.c), а также заголовочный файл (Matrix.h), который содержит прототипы функций для работы с матрицами.


