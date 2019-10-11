# maze makefile

# source
SOURCE = main.c

# compiler
CC = gcc

# compiler flags
# -ansi for ansi c standard
# -Wall for compiler warnings
CFLAGS = -Wall -ansi -pedantic

# output file (executable)
OUT = maze

# compile
all :	$(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) -o $(OUT)

# clean
clean :
	-rm $(OUT)

