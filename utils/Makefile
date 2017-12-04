
CC ?= gcc
CPP ?= g++
CFLAGS ?= -g -Wall 
LDFLAGS ?= -lpthread
CFLAGS += -L$(PROJ_DIR)/utils -I$(PROJ_DIR)/utils

objects := work.o

all: $(objects)
	@ar -r libutils.a $(objects)
	
$(objects):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	-rm *.o libutils.a


