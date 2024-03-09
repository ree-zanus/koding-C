
/* 1. Объявить массив данных типа double разме
/* 2. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположеных на главнй диаонаи  сумму лемен
/*3. расположенных на  побочной диагонали. */
/* 1.	Объявить массив данных типа int размером  н 2. *
/* 2. Ввести с консоли его значения, */
/* 3. вывести на консоль квадрат  данной матрицы.*/
#include <stdio.h>
int main()
{
    int i,j;
    int N,M;
    int x;
    do{
        printf("Введите кол-во строку: ");
        scanf("%d", &N);
        printf("Введите кол-во столбцов: ");
        scanf("%d", &M);
        double arr[N][M];
        double sum_dg = 0;
        double sum_dp = 0;
        printf("Введите значения массива:");
        
        for(int i = 0; i<N; i++) 
        {
            for(int j = 0; j<M; j++) 
            {
                scanf("%lf", &arr[i][j]); 
            }
        }    
            for (int i = 0; i <= N-1; i++) 
        {
            sum_dg += arr[i][i];
            sum_dp += arr[i][N-i-1]; 
        } 
            printf("Сумма по главной диагонали: %lf\n", sum_dg);
            printf("Сумма по побочной диагонали: %lf\n", sum_dp);
            printf("Для старта нажмите 1");
            scanf("%d", &x);
    } while (x==1); 
    return 0;
}





/* 1.Объявить массив данных типа int размером 2 на 2.*/
/* 2. Ввести с консоли его значения, */
/* 3. вывести на консоль квадрат данной матрицы.*/
#include <stdio.h>

int main() {
    int i,j;
    int N,M;
    
    printf("Введите кол-во строку: ");
    scanf("%d", &N);
    printf("Введите кол-во столбцов: ");
    scanf("%d", &M);
    double arr[N][M];
    double kv[N][M];
    printf("Введите значения массива:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            kv[i][j] = 0;
            for (int k = 0; k < M; k++)
                kv[i][j] += arr[i][k]*arr[k][j];
        }
    }
    printf("Квадрат матрицы:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%lf ", kv[i][j]);
        }
        printf("\n");
    }
    
    return 0; 
}
