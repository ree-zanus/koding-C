//Ввести с консоли строку символов произвольной длины (до 80 символов). 
//Поменять в ней все маленькисимволы ‘a’ и ‘b’ на заглавны
//Вывести на консоль полученнустрок.
#include <stdio.h>

int main() {
    char str[80];
    int i = 0;

    printf("Введите строку символов до 80 символов:");
    fgets(str, 80, stdin); //  Эта функция считывает строку (символы плюс символ новой строки) из стандартного ввода (stdin) и сохраняет ее в массиве str. 

    while (str[i] != '\0') { // цикл выполняется, пока не достигнут нулевой символ, обозначающий конец строки.
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = str[i] - 32; // Преобразуем в заглавную букву
        }
        i++;
    }

    printf("Измененная строка: %s", str);

    return 0;
}
