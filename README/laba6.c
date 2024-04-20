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
