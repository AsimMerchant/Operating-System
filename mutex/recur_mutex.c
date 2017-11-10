#define _GNU_SOURCE
#include<stdio.h>
#include <pthread.h>
/*#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, __PTHREAD_SPINS, { 0, 0 } } }*/


int count;
pthread_mutex_t cont_mutex= PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void *inc_thread (void *data)
{
	while(1)
	{
		//int pthread_mutex_lock (pthread_mutex_t *__mutex)
		pthread_mutex_lock (&cont_mutex);
		pthread_mutex_lock (&cont_mutex);
		count++; 
		printf("Inc: %d\n", count);
		//int pthread_mutex_unlock (pthread_mutex_t *__mutex);
		pthread_mutex_unlock (&cont_mutex);
		pthread_mutex_unlock (&cont_mutex);
	}
}


void *dec_thread (void *data)
{
	while(1)
	{
		//int pthread_mutex_lock (pthread_mutex_t *__mutex)
		pthread_mutex_lock (&cont_mutex);
		pthread_mutex_lock (&cont_mutex);
		count--;
		printf("Dec: %d\n", count);
		//int pthread_mutex_unlock (pthread_mutex_t *__mutex)
		pthread_mutex_unlock (&cont_mutex);
		pthread_mutex_unlock (&cont_mutex);
	}
}


int main()
{
	pthread_t inc_tid, dec_tid; 
	
		
	//int pthread_mutex_init (pthread_mutex_t *__mutex, const pthread_mutexattr_t *__mutexattr)
	//pthread_mutex_init (&cont_mutex, NULL);
	
	
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	pthread_create(&inc_tid, NULL, inc_thread, NULL);
	pthread_create(&dec_tid, NULL, dec_thread, NULL);
	
	
	//int pthread_join(pthread_t thread, void **retval);
	pthread_join(inc_tid,NULL);
	pthread_join(dec_tid,NULL);
	
	//int pthread_mutex_destroy (pthread_mutex_t *__mutex)
	pthread_mutex_destroy (&cont_mutex);
	return 0;

}
