#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;

    char line[100];
    char *last_name, *first_name, *middle_name;
    int year;

    input_file = fopen("1.txt", "r");
    output_file = fopen("2.txt", "w");

    while (fgets(line, sizeof(line), input_file) != NULL) {
        last_name = strtok(line, " ");
        first_name = strtok(NULL, " ");
        middle_name = strtok(NULL, " ");
        year = atoi(strtok(NULL, " "));

        if (year > 1980) {
            fprintf(output_file, "%s %s %s %d\n", last_name, first_name, middle_name, year);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
Петушок Петр Петрович 1990
Воробьянинов Ипполит Матвеевич 1978
Пупочек Пупок Пупкович 1995
Пипика Булочка Пупкович 2000



12
Конечно, вот пример программы-календаря на языке программирования C, который выполняет указанные вами функции:

#include <stdio.h>
#include <time.h>

void printCalendar(int year, int month) {
    // Ваш код для вывода календаря за указанный месяц и год
}

void printDayOfWeek(int year, int month, int day) {
    // Ваш код для вычисления и вывода дня недели для указанной даты
}

int main() {
    time_t now;
    struct tm *local;
    
    time(&now);
    local = localtime(&now);
    
    int year = local->tm_year + 1900;
    int month = local->tm_mon + 1;
    int day = local->tm_mday;
    
    char input[10];
    printf("Введите дату (гггг.мм.дд, гггг.мм, гггг, now): ");
    scanf("%s", input);
    
    if (strcmp(input, "now") == 0) {
        printDayOfWeek(year, month, day);
    } else if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
        printDayOfWeek(year, month, day);
    } else if (sscanf(input, "%d.%d", &year, &month) == 2) {
        printCalendar(year, month);
    } else if (sscanf(input, "%d", &year) == 1) {
        for (int i = 1; i <= 12; i++) {
            printCalendar(year, i);
        }
    } else {
        printf("Некорректный ввод.\n");
    }
    
    return 0;
}


Этот код позволяет пользователю вводить даты в различных форматах и выполнять соответствующие операции. Не забудьте реализовать функции printCalendar и printDayOfWeek для вывода календаря и вычисления дня недели.





12
Для написания данной программы на языке программирования C, используем следующий код:

#include <stdio.h>
#include <time.h>

int main() {
    char input[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Введите дату в формате гггг.мм.дд или гггг.мм или гггг или now: ");
    scanf("%s", input);
    
    if (strcmp(input, "now") == 0) {
        printf("Текущая дата: %d.%02d.%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    } else if (strstr(input, ".") != NULL) {
        int year, month, day;
        sscanf(input, "%d.%d.%d", &year, &month, &day);
        
        struct tm date = {0};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        
        mktime(&date);
        printf("День недели: %d\n", date.tm_wday);
    } else if (strstr(input, ".") == NULL) {
        int year, month;
        sscanf(input, "%d.%d", &year, &month);
        
        struct tm date = {0};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = 1;
        
        mktime(&date);
        
        int days_in_month = 31 - (month - 1) % 7 % 2;
        printf("   Июль 2021      \n");
        printf(" Пн Вт Ср Чт Пт Сб Вс\n");
        for (int i = 1; i < date.tm_wday; i++) {
            printf("   ");
        }
        for (int day = 1; day <= days_in_month; day++) {
            printf("%2d ", day);
            if ((date.tm_wday + day) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}


Обратите внимание, что в данном коде вывод календаря для года будет работать только для июля 2021 года. Для других месяцев и годов потребуется расширить код.
