
CFILES = example.c
COUT = example
CC = gcc

all: 
	$(CC) -Wall $(CFILES) -o $(COUT)
