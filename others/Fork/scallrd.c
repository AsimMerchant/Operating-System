#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
  char g[10];
  int myfirstfile;
  myfirstfile=open("file.txt", O_RDWR);
  read(myfirstfile, g, 7);
  printf("%s\n",g);
}
