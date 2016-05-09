CC=gcc
CFLAGS= -std=c99 -Wall -D_GNU_SOURCE -g #args for the compilation
LDFLAGS=
EXEC=projet-info #Name of the executable
LIBS=-lm
BIN=bin/
BIN_PATH=./bin/
SRC_PATH=./src/
OBJ_PATH=./build/
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, build/%.o, $(SRC))

all: $(EXEC)

projet-info: $(OBJ)
	$(CC) -o $(BIN)/$@ $^ $(LDFLAGS)
	@ln -sf $(BIN_PATH)$(EXEC) $(EXEC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -I./include -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ_PATH)*.o

mrproper: clean
	@rm -rf $(BIN_PATH)$(EXEC)
	@rm -rf $(EXEC)
