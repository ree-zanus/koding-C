Ввести с консоли строку символов произвольной лины до 80 симоло). Поменять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывест на кнсоль полученную строку.
  int main() {
    char str80;
    int i = 0;

    printf("Введите строку символов до 80 символов:");
    fgets(str, 80, stdin);

    while (stri != '\0') {
        if (stri == 'a' || stri == 'b') {
            stri = stri - 32; // Преобразуем в заглвнуюбуву
        }
        i++;
    }

    printf("Измененная строка: %s", str);

    return 0;
}
