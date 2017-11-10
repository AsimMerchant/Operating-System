#include <stdio.h>
#include <pthread.h>

int completed=0;

pthread_mutex_t completed_mutex;
pthread_cond_t cv;

void * wait_thread (void *data)
{
  pthread_mutex_lock (&completed_mutex);
  while(completed==0)
  {
    printf("Conditional variable not set\n");
    pthread_cond_wait(&cv, &completed_mutex);
  }
  pthread_mutex_unlock (&completed_mutex);
  printf("got completed=1\n");
}
void * update_thread (void *data)
{
  pthread_mutex_lock (&completed_mutex);
  printf("got mutex\n");
  completed=1;
  printf("update completed\n");
  printf("Relese Mutex\n");
  pthread_mutex_unlock (&completed_mutex);
  pthread_cond_signal(&cv);
}

int main(int argc, char const *argv[])
{

  pthread_t wait_tid, update_tid;
  pthread_mutex_init (&completed_mutex, NULL);
  pthread_cond_init(&cv, NULL);

  pthread_create(&wait_tid, NULL, wait_thread, NULL);
  pthread_create(&update_tid, NULL, update_thread, NULL);


  pthread_join(wait_tid, NULL);
  pthread_join(update_tid, NULL);

  pthread_mutex_destroy (&completed_mutex);
  pthread_cond_destroy(&cv);

  return 0;
}
