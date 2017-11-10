#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t input2calsem;
sem_t cal2inputsem;


int a,b,sum; 

void *input_thread(void *data)
{
	while(1)
	{
		sem_wait(&cal2inputsem);
		scanf("%d %d", &a, &b);
		sem_post(&input2calsem);	
	}
}


void *cal_thread(void *data)
{
	while(1)
	{
		sem_wait(&input2calsem);
		sum= a+b;
		printf("Sum= %d\n", sum);
		sem_post(&cal2inputsem);
	}
}

int main()
{
	pthread_t input_tid, cal_tid;
		
	sem_init(&input2calsem, 0, 0);
	sem_init(&cal2inputsem, 0, 1);
	//int sem_init(sem_t *sem, int pshared, unsigned int value);
	
	pthread_create(&input_tid, NULL, input_thread, NULL);
	pthread_create(&cal_tid, NULL, cal_thread, NULL);
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	
	pthread_join(input_tid, NULL);
	pthread_join(cal_tid, NULL);
	//int pthread_join(pthread_t thread, void **retval);
	sem_destroy(&input2calsem);
	sem_destroy(&cal2inputsem);
	
	return 0;
}

