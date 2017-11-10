#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
  fork();
  printf("%d %d\n", getpid(), getppid());
}
