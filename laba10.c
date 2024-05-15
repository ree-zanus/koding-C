 
#include <stdio.h>
#define Max(a, b) (a) >= (b) ? (a) : (b)
 
int main()
{
    int num[100];
    int count = 0;
    
    printf("Введите числа:");

    while (scanf("%d", &num[count])==1){
        
  //      printf("otvet %d", num[count]);
        
        if (num[count]==1) break;
        
        count++;
    }
    printf("Massive is: ");
    for (int i=0; i<=count;i++){
        
        printf(" %d ", num[i]);
    }
    
    int max_num = num[0];
    for (int i=1; i<count;i++){
        
        max_num= Max(max_num, num[i]);
    }
    printf("Максимальное числo: %d\n",max_num);
    return 0;
}

