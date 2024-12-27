#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Если нет аргументов, читаем со стандартного ввода и выводим в стандартный вывод
        int c;
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
    } else {
        // Проходим по всем аргументам
        for (int i = 1; i < argc; i++) {
            cat_file(argv[i]);
        }
    }

    return 0;
}