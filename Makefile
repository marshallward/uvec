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
	$(CC) -I$(INC) -L$(LIB) test/check_uvec.c -luvec -lcheck

clean:
	rm -rf $(LIB)/libuvec.a $(OBJ)/uvec.o
