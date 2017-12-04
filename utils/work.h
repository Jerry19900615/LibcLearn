#ifndef WORK_H
#define WORK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GNUC__
#error "PLS use gcc"
#endif

typedef void(*work_func)(void*);

int work_run(int cpu, work_func func, void *param, int main_thread);

#ifdef __cplusplus
}
#endif

#endif
