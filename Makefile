

CFLAGS:=-g -Wall
LDFLAGS:=
CC:=gcc
CPP:=g++

PROJ_DIR:=$(shell pwd)

export CFLAGS LDFLAGS CC CPP PROJ_DIR


subdirs:= utils io

all:  subdir tags

.PHONY:subdir
subdir:
	@for dir in $(subdirs); do \
		$(MAKE) -C $$dir; \
	done

tags: force
	-ctags -R ./*
force:;

.PHONY:clean
clean:
	@for dir in $(subdirs); do \
		$(MAKE) -C $$dir $@; \
	done
	-rm tags
