
CC ?= gcc
CPP ?= g++
CFLAGS ?= -g -Wall 
LDFLAGS ?= 
CFLAGS += -L$(PROJ_DIR)/utils -I$(PROJ_DIR)/utils

lib_objs := libwork.o

test_objs := test_libwork.o 
test_tgt:=test_libwork

LDFLAGS += -lpthread

objs := $(lib_objs) $(test_objs)

all: $(objs) $(test_tgt)
	@ar -r libwork.a $(objects)
	
$(objs):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(test_tgt): $(objs)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	-rm $(objs) libwork.a $(test_tgt)


