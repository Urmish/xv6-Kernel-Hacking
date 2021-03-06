// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

//#include "types.h"
//#include "stat.h"
//#include "user.h"
//
//int
//main(int argc, char *argv[])
//{
//  int clonepid = 0;
//  printf(1, "%s", "** Placeholder program for grading scripts **\n");
//  int * ptr = (int *) malloc (4096);
//  printf(1,"ptr value passed is = %p\n", ptr);
//  clonepid = clone(ptr);
//  printf(1, "clonepid is %d\n",clonepid);
//  if (getpid() == clonepid)
//  {
//    printf(1,"I am clone with pid : %d\n", clonepid);
//    while (1);
//  }
//  
//  else
//  {
//    printf(1,"I am parent pid : %d\n", getpid());
//    while(1);
//  }
//
//  lock(ptr);
//  unlock(ptr);
//  join();
//  exit();
//}
//

#include "types.h"
#include "stat.h"
#include "user.h"

int stack[4096] __attribute__ ((aligned (4096)));
int x = 0;

int main(int argc, char *argv[]) {
  printf(1, "Stack is at %p\n", stack);
  //int tid = fork();
  int tid = clone(stack);
  printf(1,"tid is %d\n",tid);

  ////printf(1,"\nTRY TO PRINT THIS\n");

  if (tid < 0) {
    printf(1, "error!\n");
  } 
  ////else if (tid == getpid()) {
  else if (tid == 0) {
    // child
  printf(1,"\nCHILD TRY TO PRINT THIS\n");
    for(;;) {
      x++;
      sleep(100);
    }
  } else {
     //parent
     for(;;) {
      printf(1, " PARENT pid = %d x = %d\n", getpid(),x);
      sleep(100);
    }
    //wait();
  }

  exit();
}
