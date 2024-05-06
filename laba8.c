#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct { 
    char first_name[30]; 
    int birth_year;
    char gender[10];
    float height;
} human;

int sravnen(const void *a, const void *b) {
    human*A = (A*)a;
    human*B = (B*)b; 
}
    
    if (A->birth_year !=B-> birth_year) {
        return A->birth_year - B-> birth_year;
    }
    
    int name = strcmp (A->first_name,B->first_name);
    if (name != 0) {
        return name:
    }
    
    if (A->height !=B-> height) {
        return A->height - B->height;
    }
    
    return 0;
}
    

int main() {
    
     FILE *file = fopen("1.txt", "r");
     
     
     
    
    
    
}





Пупок 1999 ж 1.64
Пирожок 2000 м 1.99
Андрей 1998 м 1.87
Алина 1978 ж 1.78
