#include<stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int main()
{
	int fd,clos;
	
	ssize_t retsize;
	fd=open("demowrite.txt", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);//int open(const char *pathname, int flags, mode_t mode);
	if(fd==-1)
	{
		perror("fd");
	}
	else
	{
		retsize=write(fd,"Hello\n",6);//ssize_t write(int fd, const void *buf, size_t count);
		if(retsize==0)
		{
			printf("Data not written\n");	
		}
		else if(retsize==-1)
		{
			perror("retsize");
		}
		else
		{
			 clos=close(fd);//int close(int fd);
			 if(clos==0)
			 {
			 	perror("clos");
			 	return 0;
			 }
			 else if(clos==-1)
			 {
			 	perror("clos");
			 	return 0;
			 }
		}
		
	}
	
	return 0;
}
