#include<stdio.h>


 #include <unistd.h>


int main()
{
	int piperesult, fd_p1[2],fd_p2[2];
	
	pid_t id;
	
	
	piperesult=pipe(fd_p1);//int pipe(int pipefd[2]);
	if(piperesult==0)
	{
		piperesult=pipe(fd_p2);
		if(piperesult==0)
		{
			id=fork();//pid_t fork(void);
			if (id==0)
			{
				
			}
			else if(id !=-1 && id !=0)
			{
				
			}
			else
			{
				perror("id");
			}
		}
		else
		{
			perror("piperesult2");
		}
		
	}
	else
	{
		perror("piperesult1");
	}
	return 0;
}
