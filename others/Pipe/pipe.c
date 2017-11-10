#include <unistd.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
  int fd[2], x;
  char rd[15];
  pid_t y;
  x=pipe(fd);
  if(x==0)
  {
    perror("1");
    printf("Pipe sucessful\n");
    y=fork();
    if (y)
    {
      printf("M in parent\n");
      write(fd[1], "Data received\n", 14);
    }
    else
    {
      printf("m in child\n");
      read(fd[0], rd, 13);
      printf("%s\n",rd);
    }
  }
  else
  {
    perror("2");
    printf("Not Successful");
  }

  return 0;
}
