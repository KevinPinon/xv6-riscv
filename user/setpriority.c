#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    fprintf(2, "Usage: setpriority <prio>\n");
    exit(-1);
  }
  int prio = atoi(argv[1]);
  if(setpriority(prio) < 0){
    fprintf(2, "setpriority failed\n");
    exit(-1);
  }
  exit(0);
}
