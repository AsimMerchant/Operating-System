#include <unistd.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
  int fd[2],fd1[2], x, x1;
  char rd[15], rd1[15];
  pid_t y;
  x=pipe(fd);
  x1=pipe(fd1);
  if(x==0)
  {
    perror("1");
    printf("Pipe sucessful\n");
    y=fork();
    if (y)
    {
      printf("M in parent\n");
      write(fd[1], "Data received\n", 14);
      read(fd1[0], rd1, 13);
      printf("Back to parent\n");
      printf("%s\n",rd1);
    }
    else
    {
      perror("2");
      printf("m in child\n");
      read(fd[0], rd, 13);
      printf("%s\n",rd);
      write(fd1[1], "Sending back\n", 13);
    }
  }
  else
  {
    perror("2");
    printf("Not Successful");
  }

  return 0;
}
