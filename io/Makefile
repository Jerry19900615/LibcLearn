

CC ?= gcc
CPP ?= g++
CFLAGS ?= -g -Wall
LDFLAGS ?= 

CFLAGS += -L$(PROJ_DIR)/utils -I$(PROJ_DIR)/utils
LDFLAGS += -lutils -lpthread

TARGETS:=1 2 3 4 5

all: $(TARGETS)

$(TARGETS):%:%.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	-rm $(TARGETS) *.o


