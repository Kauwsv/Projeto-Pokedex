CC = gcc
EXE = main.exe
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces -g

SRCS = $(wildcard src/*.c)
HDRS = $(wildcard src/*.h)

$(EXE): 
	$(CC) -o $(EXE) $(CFLAGS) $(SRCS) $(HDRS)

clean: 
	del -r $(EXE) 

run: 
	./$(EXE)

.PHONY: clean run
