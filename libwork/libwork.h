#ifndef WORK_H
#define WORK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GNUC__
#error "PLS use gcc"
#endif


int work_run(int cpu, void(*func)(void*), void *param, int main_thread);

#ifdef __cplusplus
}
#endif

#endif
