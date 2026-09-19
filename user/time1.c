#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    fprintf(2, "Usage: time1 <command> [args...]\n");
    exit(1);
  }

  int start_time = uptime();

  int pid = fork();
  if(pid < 0){
    fprintf(2, "time1: fork failed\n");
    exit(1);
  }

  if(pid == 0){
    // Child process: execute target program
    exec(argv[1], &argv[1]);
    fprintf(2, "time1: exec %s failed\n", argv[1]);
    exit(1);
  } else {
    // Parent process: wait for child and calculate elapsed time
    int status;
    wait(&status);
    int end_time = uptime();
    int elapsed = end_time - start_time;
    printf("elapsed time: %d ticks\n", elapsed);
  }

  exit(0);
}
