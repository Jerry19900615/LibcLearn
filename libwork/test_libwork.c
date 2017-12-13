#include "libwork.h"
#include <stdio.h>
#include <unistd.h>

int work_running = 0;

void work2(void *p){
	int i;
	for(i = 0;i < 10000;i ++){
		printf("work2 running\n");
	}
	work_running --;
}
void work1(void *p){
	(void)p;
	int i;
	for(i = 0;i < 10000;i++){
		printf("work1 running\n");
	}
	
	work_running --;
}


void work_poll(void *p){
	while(work_running){
		sleep(1);
	}
}

int main(){
	//work_run(work1, NULL, 0);
	work_run_affinity(0,work1, NULL, 0);
	work_running ++;
	//work_run(work2, NULL, 0);
	work_run_affinity(1, work2, NULL, 0);
	work_running ++;
	work_run(work_poll,NULL, 1);
	return 0;
}
