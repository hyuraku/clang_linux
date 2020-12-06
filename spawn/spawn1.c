#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char *argv[]){
  pid_t pid;

  if (argc != 3) {
    fprintf(stderr, "Usage %s\n", argv[0]);
    exit(1);
  }
  pid = fork();
  if (pid < 0){
    fprintf(stderr, "fork(2) failed");
    exit(1);
  }
  if (pid == 0){
    execl(argv[1], argv[1], argv[2],NULL);
    perror(argv[1]);
    exit(99);
  }else{
    int status;

    waitpid(pid, &status, 0);
    printf("child (PID=%d) finished; ",  pid);
    if(WIFEXITED(status))
      printf("exit, status=%d\n", WIFEXITED(status));
    else if (WIFSIGNALED(status))
      printf("signal");
    else
      printf("abnormal");
    exit(0);
  }
}
