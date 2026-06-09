CC = gcc
CFLAGS = -Wall -Wextra -I./include
LDFLAGS = -L./build/lib

TARGET = build/bin/program
LIBRARY = build/lib/libgame.a

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/obj/%.o, $(SRCS))

all: $(LIBRARY) $(TARGET)

$(LIBRARY): $(OBJS)
	@mkdir -p build/lib
	ar rcs $@ $^

build/obj/%.o: src/%.c
	@mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@mkdir -p build/bin
	$(CC) $^ $(LDFLAGS) -lgame -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build/

.PHONY: all clean run
