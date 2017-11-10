#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
  
  if(fork())
  {
      printf("%d %d\n", getpid(), getppid());
  }
  else
  {
      printf("%d %d\n", getpid(), getppid());
  }
}
