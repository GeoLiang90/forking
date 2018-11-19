#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main(){
  srand(time(NULL));
  int parent = getpid();
  printf("I am a parent with a pid of: %d \n", parent);
  int f = fork();
  int z = 0;
  if(f){
    z = fork();
  }

  int fgen = rand() % (16) + 5;
  int zgen = rand() % (16) + 5;


  if (getppid() == parent){
    int gen = 0;
    if (f){
      gen = fgen;
    }
    else{
      gen = zgen;
    }
    printf("I am a child with a pid of: %d \n", getpid());
    sleep(gen);
    printf("Finished. I am a child. My pid is: %d\n", getpid());
    return gen;
  }
  int stat;
  int cpid = wait(&stat);
  printf("Child with pid %d terminated and slept for %d seconds \n", cpid, WEXITSTATUS(stat));
  return 0;
}
