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
