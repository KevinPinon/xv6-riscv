#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"
#include "types.h"

struct rusage {
  uint cputime;
};

#ifndef _PROC_H_
enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
#endif


struct pstat {
    int pid;                // Process ID
    enum procstate state;   // Process state
    uint64 size;            // Size of process memory (bytes)
    int ppid;               // Parent process ID
    char name[16];          // Process command name
    int priority;           // Process priority (Task 2)
    uint readytime;         // Time when process entered RUNNABLE state (Task 3)
};

#endif
