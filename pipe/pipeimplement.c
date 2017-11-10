#include<stdio.h>

#include <unistd.h>


int main()
{
	int piperesult,fd[2];
	
	pid_t id;
	
	unsigned char buffer[128];
	
	piperesult=pipe(fd);//int pipe(int pipefd[2]);
	if(piperesult==-1)
	{
		perror("piperesult");
	}
	else if(piperesult==0)
	{
		 id=fork();//pid_t fork(void);
		 if(id==-1)
		 {
		 	perror("id");
		 }
		 else
		 {
		 	if(id==0)
		 	{
		 		close(fd[1]);//int close(int fd);
		 		read(fd[0],buffer,128);//ssize_t read(int fd, void *buf, size_t count);
		 		printf("read:%s",buffer);
		 	}
		 	else
		 	{
		 		close(fd[0]);//int close(int fd);
		 		write(fd[1],"Hello\n",6);
		 		close(fd[1]);//ssize_t write(int fd, const void *buf, size_t count);
		 	}
		 }
	}
	return 0;
}
