CC = gcc

TARGET = interpreter
SRC = interpreter.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
.PHONY: clean