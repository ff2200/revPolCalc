TARGETS += $(BIN_DIR)/revPolCalc
OBJECTS = getch.o getop.o main.o stack.o

CC = gcc
CFLAGS = -g -Wall -std=gnu99
LDLIBS += -lm

MKDIR = mkdir
BIN_DIR = ./bin

all: $(BIN_DIR) $(TARGETS)

$(BIN_DIR)/revPolCalc: $(OBJECTS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(OBJECTS): calc.h 

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)


.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGETS) 
	rmdir $(BIN_DIR)

