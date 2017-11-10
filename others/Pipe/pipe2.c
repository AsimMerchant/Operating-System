#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  int fd[2],fd1[2], x, x1,a[2], sum[1];
  char rd[15], rd1[15];
  pid_t id;
  x=pipe(fd);
  x1=pipe(fd1);
  printf("Enter any 2 num for sending to child\n");
  scanf("%d %d",&a[0], &[1]);
  id=fork();
  if(x==0)
  {
    if (id)
    {
	  perror("1");
      printf("M in parent\n");
      write(fd[1],a, 8);
      //write(fd[1], "b\n", 4);
      read(fd1[0], &sum, 4);
      printf("Back to parent\n");
      printf("sum= %d\n",sum[0]);
    }

    else
    {
      perror("2");
      printf("m in child\n");
      read(fd[0], a, 8);
      //read(fd[0], rdb, 4);
      sum[0]=a[0]+a[1];
      //printf("%s\n",rd);
      write(fd1[1], &sum,4);
    }
  }
  else
  {
    perror("2");
    printf("Not Successful");
  }

  return 0;
}
