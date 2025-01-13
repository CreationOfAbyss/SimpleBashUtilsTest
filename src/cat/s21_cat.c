#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

enum Flags {
    NUMBER_LINES = 1 << 0,
    SQUEEZE_BLANK = 1 << 1
};

void cat_file(const char *filename, int flags) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "s21_cat: %s: %s\n", filename, strerror(errno));
        return;
    }

    int c;
    int line_number = 1;
    int last_char = '\n';

    while ((c = fgetc(file)) != EOF) {
        if (flags & NUMBER_LINES && last_char == '\n') {
            printf("%6d  ", line_number++);
        }

        if (flags & SQUEEZE_BLANK && c == '\n' && last_char == '\n') {
            continue;
        }

        putchar(c);
        last_char = c;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    int flags = 0;
    int i;

    if (argc == 1) { // Обработка случая, когда не указан ни один файл.
        int c;
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
        return 0;
    }

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            // Обработка флагов
            for (int j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                    case 'n':
                        flags |= NUMBER_LINES;
                        break;
                    case 's':
                        flags |= SQUEEZE_BLANK;
                        break;
                    default:
                        fprintf(stderr, "mycat: неверный параметр: -%c\n", argv[i][j]);
                        return 1;
                }
            }
        } else {
            // Аргумент — имя файла
            cat_file(argv[i], flags);
        }
    }
    return 0;
}