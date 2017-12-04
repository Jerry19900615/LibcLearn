

CC ?= gcc
CPP ?= g++
CFLAGS ?= -g -Wall
LDFLAGS ?= 
PROJ_DIR ?= $(shell pwd)/../

CFLAGS += -L$(PROJ_DIR)/utils -I$(PROJ_DIR)/utils
LDFLAGS += -lutils -lpthread

TARGETS:=1 2 3 4 5 6 7

all: $(TARGETS)

$(TARGETS):%:%.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	-rm $(TARGETS) *.o


