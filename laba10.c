 #include <stdio.h>
#define Max(a, b) ((a) >= (b) ? (a) : (b))

int main() {
    int n;
    printf("Введите количество чисел: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Введите числа: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        max = Max(max, numbers[i]);
        sum += numbers[i];
    }

    int arif = sum / n;

    printf("Максимальное число: %d\n", max);
    printf("Среднее арифметическое: %d\n", arif);

    return 0;
}
