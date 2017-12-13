#ifndef WORK_H
#define WORK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GNUC__
#error "PLS use gcc"
#endif


int work_run(void(*func)(void*), void *param, int is_main_thread);

int work_run_affinity(int cpu, void(*func)(void*), void *param, int is_main_thread);

#ifdef __cplusplus
}
#endif

#endif
