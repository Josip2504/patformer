CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = main.c src/glad.c

TARGET = game

LIBS = -lSDL2 -lopengl32

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
