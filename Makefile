# Makefile для проекта "Лабораторная работа 12"
# Компьютерные игры - структуры, сортировка, библиотеки

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -I./include
LDFLAGS = -L./build/lib

# Имена
TARGET = build/bin/program
LIBRARY = build/lib/libgame.a
# Для динамической библиотеки (закомментируйте статическую и раскомментируйте эту):
# LIBRARY = build/lib/libgame.so
# LDFLAGS = -L./build/lib -Wl,-rpath=./build/lib

# Файлы
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/obj/%.o, $(SRCS))
DEPS = $(wildcard include/*.h)

# Цель по умолчанию
all: $(LIBRARY) $(TARGET)
	@echo "✅ Сборка завершена!"

# Сборка статической библиотеки
$(LIBRARY): $(OBJS)
	@mkdir -p build/lib
	ar rcs $@ $^
	@echo "📚 Статическая библиотека создана: $@"

# Сборка объектных файлов
build/obj/%.o: src/%.c $(DEPS)
	@mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Компиляция: $<"

# Линковка исполняемого файла
$(TARGET): $(OBJS)
	@mkdir -p build/bin
	$(CC) $^ $(LDFLAGS) -lgame -o $@
	@echo "🔗 Исполняемый файл создан: $@"

# Запуск программы
run: $(TARGET)
	@echo "🚀 Запуск программы:"
	./$(TARGET)

# Очистка всех скомпилированных файлов
clean:
	rm -rf build/
	@echo "🧹 Очистка завершена!"

# Показать справку
help:
	@echo "Доступные команды:"
	@echo "  make        - полная сборка проекта"
	@echo "  make run    - собрать и запустить"
	@echo "  make clean  - удалить все собранные файлы"
	@echo "  make help   - показать эту справку"

.PHONY: all clean run help
