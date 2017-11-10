#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>

int gv_count=0;
sem_t sem4count;


void *inc_thread(void *data)
{
	while(1)
	{
		sem_wait(&sem4count);
		gv_count++;
		printf("Inc: %d\n",gv_count);
		sem_post(&sem4count);
	}
}


void *dec_thread(void *data)
{
	while(1)
	{
		sem_wait(&sem4count);
		gv_count--;
		printf("Dec: %d\n",gv_count);
		sem_post(&sem4count);
	}
}


int main()
{
	pthread_t inc_tid,dec_tid;
		
	sem_init(&sem4count, 0, 1);
	//int sem_init(sem_t *sem, int pshared, unsigned int value);
	
	pthread_create(&inc_tid, NULL, inc_thread, NULL);
	pthread_create(&dec_tid, NULL, dec_thread, NULL);
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	
	pthread_join(inc_tid, NULL);
	pthread_join(dec_tid, NULL);
	//int pthread_join(pthread_t thread, void **retval);
	sem_destroy(&sem4count);
	
	return 0;
}

