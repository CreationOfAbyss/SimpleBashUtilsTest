CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Исполняемые файлы
CAT_EXE = s21_cat
GREP_EXE = s21_grep

# Исходные файлы
CAT_SRC = s21_cat.c
GREP_SRC = s21_grep.c

# Объектные файлы
CAT_OBJ = $(CAT_SRC:.c=.o)
GREP_OBJ = $(GREP_SRC:.c=.o)

# Цель по умолчанию: сборка всех исполняемых файлов
all: $(CAT_EXE) $(GREP_EXE)

# Цель для сборки s21_cat
$(CAT_EXE): $(CAT_OBJ)
	$(CC) $(CFLAGS) $(CAT_OBJ) -o $(CAT_EXE)

# Цель для сборки s21_grep
$(GREP_EXE): $(GREP_OBJ)
	$(CC) $(CFLAGS) $(GREP_OBJ) -o $(GREP_EXE)

# Цель для создания объектных файлов для s21_cat
$(CAT_OBJ): $(CAT_SRC)
	$(CC) $(CFLAGS) -c $(CAT_SRC)

# Цель для создания объектных файлов для s21_grep
$(GREP_OBJ): $(GREP_SRC)
	$(CC) $(CFLAGS) -c $(GREP_SRC)

# Цель для очистки проекта
clean:
	rm -f $(CAT_OBJ) $(GREP_OBJ) $(CAT_EXE) $(GREP_EXE)

# Цель для удаления всех файлов
mrproper: clean
	rm -f $(CAT_EXE) $(GREP_EXE)

# Цель для пересборки всего проекта
rebuild: mrproper all

# Специальные цели
.PHONY: all clean mrproper rebuild