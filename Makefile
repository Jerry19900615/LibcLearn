

CFLAGS=-g -Wall
LDFLAGS:=-lpthread
CC:=gcc
CPP:=g++


targets:= 1 2 3 4 tags

all: $(targets) 

1: 1.o work.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

2: 2.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

3: 3.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

4: 4.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

*.o: *.c
	$(CC) $(CFLAGS) -c $< -o $@

tags: force
	-ctags *.c
force:;


clean:
	-rm *.o $(targets)
