#include <unistd.h>
#include<stdio.h>
int main()
{
  pid_t x;
  x=fork();
  printf("Hello fork\n");
}
