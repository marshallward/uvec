# Doofy
LIB=lib
OBJ=obj
SRC=src
INC=inc
TEST=test

CC=gcc
CFLAGS=-g -I$(INC) -L$(LIB)

all: $(LIB)/libuvec.a

$(LIB)/libuvec.a: $(OBJ)/uvec.o
	mkdir -p $(LIB)
	ar -cvq $@ $^

$(OBJ)/uvec.o: $(SRC)/uvec.c $(INC)/uvec.h $(INC)/types.h
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean test
test:
	$(CC) $(CFLAGS) -o $(TEST)/check_uvec $(TEST)/check_uvec.c -luvec -lcheck
	./$(TEST)/check_uvec

clean:
	rm -rf $(LIB)/libuvec.a $(OBJ)/uvec.o $(TEST)/check_uvec
