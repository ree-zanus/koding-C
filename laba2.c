
/* 1. Объявить массив данных типа double разме
/* 2. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположеных на главнй диаонаи  сумму лементо
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
            for (int i = 0; i < N; i++) 
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
    int arr[2][2];
    
    printf("Введите значения массива:\n");
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]); 
        }
    }    
    
    printf("Квадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int Kv = arr[i][j] * arr[i][j];
            printf("%d ", Kv);
        }
        printf("\n");
    }
    
    return 0;
}
