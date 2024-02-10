#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    float D, x1,x2;
    int x;
    do {
    printf("Введите коэффициент а:");
    scanf("%f",&a);
    printf("Введите коэффициент b:");
    scanf("%f",&b);
    printf("Введите коэффициент c:");
    scanf("%f",&c);
    
    D=b*b-4*a*c;
    
    if (D>0) {
       x1=(-b+sqrt(D))/(2*a);
       x2=(-b-sqrt(D))/(2*a);
       printf("Корни уравнения x1=%f, x2=%f\n", x1, x2);
    } else if (D==0) { 
        x1= -b/(2*a);
        printf("Уравнение имеет один корень x=%f\n", x1);
    } else if (D<0) {
        printf(" Уравнение не имеет корней\n");
    }
        printf("Для повторения нажмите 1");
        scanf("%d", &x);
    } while(x==1);
return 0;
}
