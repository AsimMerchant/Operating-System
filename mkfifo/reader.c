#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>


int main()
{
	int fd,clos;
	
	unsigned char buffer[128];
	int retsize;//ssize_t retsize;
	
	fd=open("namedpipe", O_RDONLY);//int open(const char *pathname, int flags, mode_t mode);
	if(fd==-1)
	{
		perror("fd");
	}
	else
	{
		//ssize_t read(int fd, void *buf, size_t count);
		retsize=read(fd,buffer,128);
		if(retsize==0)
		{
			printf("nothing to read\n");	
		}
		else if(retsize==-1)
		{
			perror("retsize");
		}
		else
		{
			 printf("read:%s sent by writer\n",buffer);
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

