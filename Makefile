CC		:= gcc
C_FLAGS := -Wall -Wextra

BIN		:= bin
SRC		:= src
LIBRARIES	:= -lncurses

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= rastreador.exe
else
EXECUTABLE	:= rastreador
endif

all: install $(BIN)/$(EXECUTABLE) 

clean:
	-$(RM) $(BIN)/$(EXECUTABLE)

install:
	sudo apt-get install libncurses-dev 

run: all 
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) $^ -o $@ $(LIBRARIES)