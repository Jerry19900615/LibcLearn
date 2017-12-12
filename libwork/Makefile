
CC ?= gcc
CPP ?= g++
CFLAGS ?= -g -Wall 
LDFLAGS ?= -lpthread
CFLAGS += -L$(PROJ_DIR)/utils -I$(PROJ_DIR)/utils

objects := libwork.o

all: $(objects)
	@ar -r libwork.a $(objects)
	
$(objects):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	-rm *.o libwork.a


