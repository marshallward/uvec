CC=gcc

# Doofy
LIB=lib
OBJ=obj
SRC=src
INC=inc

all: $(LIB)/libuvec.a

$(LIB)/libuvec.a: $(OBJ)/uvec.o
	mkdir -p $(LIB)
	ar -cvq $@ $^

$(OBJ)/uvec.o: $(SRC)/uvec.c $(INC)/uvec.h $(INC)/types.h
	mkdir -p $(OBJ)
	$(CC) -I$(INC) -o $@ -c $<

.PHONY: clean test
test:
	$(CC) -I$(INC) -L$(LIB) test/test.c -luvec

clean:
	rm -rf $(LIB)/libuvec.a $(OBJ)/uvec.o
