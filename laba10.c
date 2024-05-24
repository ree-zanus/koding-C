#include <stdio.h> 
#define Max(a, b) ((a) >= (b) ? (a) : (b)) //Затем определяется макрос Max(a, b), который возвращает максимальное значение из двух переданных ему аргументов a и b.

int main() {
    int n;
    printf("Введите количество чисел: ");
    scanf("%d", &n);

    int numbers[n]; // Создается массив numbers с размером n для хранения введенных чисел. 
    printf("Введите числа: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0]; //сохранение макисмального числа
    double sum = 0; //для сохранения суммы чисел
    for (int i = 0; i < n; i++) {
        max = Max(max, numbers[i]);
        sum += numbers[i];
    }

    int arif = sum / n;

    printf("Максимальное число: %d\n", max);
    printf("Среднее арифметическое: %d\n", arif);

    return 0;
}
