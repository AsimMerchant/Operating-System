#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
  char g[10];
  int myfirstfile;
  myfirstfile=open("file.txt", O_CREAT|O_RDWR, S_IRWXU | S_IRWXG | S_IROTH);
	perror("1");
  write(myfirstfile,"ban gya", 8);
  perror("2");
  return 0;
}
