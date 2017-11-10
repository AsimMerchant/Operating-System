#include<stdio.h>
#include <pthread.h>


void *Hellothread(void *data)
{
	printf("Welcome to thread\n");
}


int main()
{
	int threadresult;
	pthread_t threadid;
	
	printf("Before creating thread\n");
	
	threadresult=pthread_create(&threadid, NULL, Hellothread, NULL);
	 /*int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);*/
	
	printf("After creating thread\n");

	pthread_join(threadid, NULL);	
	/* int pthread_join(pthread_t thread, void **retval); */
	return 0; 	
}
