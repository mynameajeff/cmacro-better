
CFILES = examples/general.c
COUT = main_example
CC = gcc

all: 
	$(CC) -Wall $(CFILES) -o $(COUT)
