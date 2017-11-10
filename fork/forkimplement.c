#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t id,pid,ppid;
	pid=getpid();
    ppid=getppid();
	printf("before fork\n");
	printf("pid %d\n",pid);
	printf("ppid %d\n",ppid);
	id=fork();//pid_t fork(void);
	printf("after fork %d \n",id);
	pid=getpid();//pid_t getpid(void);
    ppid=getppid();//pid_t getppid(void);
	printf("pid %d\n",pid);
	printf("ppid %d\n",ppid);
	return 0;
}
