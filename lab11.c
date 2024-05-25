#include "math_operations.h"
#include <stdio.h>

int main() {
    int n;
    printf("Введите кол-во чисел: ");
    scanf("%d", &n);

    double value;
    printf("Введите %d числа:\n", n);

    double numbers[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &value);
        numbers[i] = value;
    }

    double result_sum = sum(n, numbers[0], numbers[1], numbers[2],numbers[3],numbers[4],numbers[5],numbers[6]); // Передавайте числа отдельно
    double result_max = max(n, numbers[0], numbers[1], numbers[2],numbers[3],numbers[4],numbers[5],numbers[6]); // Передавайте числа отдельно
    double result_min = min(n, numbers[0], numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6]); // Передавайте числа отдельно
    double result_avg = average(n, numbers[0], numbers[1], numbers[2],numbers[3],numbers[4],numbers[5],numbers[6]); // Передавайте числа отдельно


    printf("Sum: %.2f\n", result_sum);
    printf("Max: %.2f\n", result_max);
    printf("Min: %.2f\n", result_min);
    printf("Average: %.2f\n", result_avg);
    arr(5,'q','w','e','r','r');



    return 0;
}
//math_operations.h
#ifndef MATHOPERATIONSH
#define MATHOPERATIONSH


double sum(int count, ...);
double max(int count, ...);
double min(int count, ...);
double average(int count, ...);
void printCharacters(int count, ...);
char arr(int count, ...);

#endif





//math_operations.c
#include "math_operations.h"
#include <stdarg.h>
#include <stdio.h>

double sum(int count, ...) {
    double total = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        total += va_arg(args, double);
    }

    va_end(args);
    return total;
}

double max(int count, ...) {
    va_list args;
    va_start(args, count);

    double max_val = va_arg(args, double);

    for (int i = 1; i < count; ++i) {
        double val = va_arg(args, double);
        if (val > max_val) {
            max_val = val;
        }
    }

    va_end(args);
    return max_val;
}

double min(int count, ...) {
    va_list args;
    va_start(args, count);

    double min_val = va_arg(args, double);

    for (int i = 1; i < count; ++i) {
        double val = va_arg(args, double);
        if (val < min_val) {
            min_val = val;
        }
    }

    va_end(args);
    return min_val;
}

double average(int count, ...) {
    double total = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        total += va_arg(args, double);
    }

    va_end(args);

    return count > 0 ? total / count : 0;
}

char arr(int count, ...) {
    char alphabeta;
    va_list args;
    int i = 0;
    //         printf (" %d ", i);      
    
    va_start(args, count);
     //    printf (" %d ", i);      
    for (int i = 0; i < count; ++i) {
        alphabeta = va_arg(args, int);
      //   printf (" %d ", i);       
        printf (" %c ", alphabeta);
    }

    va_end(args);

    return 0;
}



void printCharacters(int count, ...) {
    printf("Введите %d символа:\n", count);

    char character;
    for (int i = 0; i < count; ++i) {
        scanf(" %c", &character); // Пробел перед %c для игнорирования символов новой строки
        printf("%c ", character);
    }
}

