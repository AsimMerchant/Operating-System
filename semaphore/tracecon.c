#include<stdio.h>

#include <pthread.h>

int gv_count=0;

void *inc_thread(void *data)
{
	while(1)
	{
		gv_count++;
		printf("Inc: %d\n",gv_count);
	}
}
	void *dec_thread(void *data)
{
	while(1)
	{
		gv_count--;
		printf("Dec: %d\n",gv_count);
	}
}


int main()
{
	pthread_t inc_tid,dec_tid;
	
	pthread_create(&inc_tid, NULL, inc_thread, NULL);
	pthread_create(&dec_tid, NULL, dec_thread, NULL);
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	
	pthread_join(inc_tid, NULL);
	pthread_join(dec_tid, NULL);
	//int pthread_join(pthread_t thread, void **retval);
	
	return 0;
}
