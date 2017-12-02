#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include "work.h"

int xxx = 0;

void a(void*p){
	printf("begin\n");
	while(xxx == 0){
		printf("tick\n");
	}
	printf("end\n");
}

void b(void *p){
	int i;
	printf("in sub thread\n");
	for(i = 0;i < 10000;i ++){
		printf("%d\n", i);
	}
	xxx = 1;
}


int main(int argc,char **argv){
	work_run(0, b, NULL, 0);
	work_run(1, a, NULL, 1);
	return 0;
}
