
#define _GNU_SOURCE

#include "libwork.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>


typedef struct {
	int cpu;
	void(*func)(void*);
	void *param;
}work_param_t;


static void *__work_run_thread(void *param){
	work_param_t *p = (work_param_t*)param;
	int cpu = p->cpu;
	if(cpu >= 0){
		cpu_set_t cpu_set;	
		pthread_t tid = pthread_self();
		CPU_ZERO(&cpu_set);
		CPU_SET(cpu, &cpu_set);
		if(-1 == pthread_setaffinity_np(tid, sizeof(cpu_set), &cpu_set)){
			fprintf(stderr, "work_run: sched_setaffinity  to cpu %d error\n",cpu);
			return NULL;
		}
		else if(-1 == pthread_getaffinity_np(tid, sizeof(cpu_set), &cpu_set)){
			fprintf(stderr, "work_run: sched_getaffinity error\n");
			return NULL;
		}
		else if(!CPU_ISSET(cpu, &cpu_set)){
			fprintf(stderr, "set affinity to cpu %d error\n",cpu);
			return NULL;
		}
	}

	p->func(p->param);
	free(p);
	return NULL;
}

static void *__work_run_proc(void *param){
	work_param_t *p = param;
	int cpu = p->cpu;
	if(cpu >= 0){
		cpu_set_t cpu_set;	
		pid_t pid;
		pid = getpid();
		CPU_ZERO(&cpu_set);
		CPU_SET(cpu, &cpu_set);
		if(-1 == sched_setaffinity(pid, cpu+1, &cpu_set)){
			fprintf(stderr, "work_run: sched_setaffinity of pid %d to cpu %d error\n", pid, cpu);
			return NULL;
		}
		else if(-1 == sched_getaffinity(pid, sizeof(cpu_set), &cpu_set)){
			fprintf(stderr, "work_run: sched_getaffinity of pid %d error\n", pid);
			return NULL;
		}
		else if(!CPU_ISSET(cpu, &cpu_set)){
			fprintf(stderr, "set affinity of pid %d to cpu %d error\n", pid, cpu);
			return NULL;
		}
	}
	p->func(p->param);
	free(p);
	return NULL;
}

int work_run_affinity(int cpu, void(*func)(void*), void *param, int is_main_thread){
	work_param_t *p = (work_param_t*)malloc(sizeof(work_param_t));
	if(!p){
		fprintf(stderr, "work run error\n");
		return -1;
	}
	p->cpu = cpu;
	p->func = func;
	p->param = param;

	if(is_main_thread){
		__work_run_proc(p);
	}
	else {
		int rv;
		pthread_t tid;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		rv = pthread_create(&tid, &attr, __work_run_thread, p);
		if(rv){
			perror("pthead_create()");
		}
		pthread_attr_destroy(&attr);
	}
	return 0;
}


int work_run(void(*func)(void*), void *param, int is_main_thread){
	return work_run_affinity(-1, func, param, is_main_thread);
}

