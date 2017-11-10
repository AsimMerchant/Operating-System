#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t rwl;
int count=0;

void* Inc_thread (void* data)
{
  pthread_rwlock_wrlock (&rwl);
  printf("Inside Inc_thread\n");
  count++;
  pthread_rwlock_unlock (&rwl);
  printf("Data Incremented\n");
}

void* LCD_thread (void* data)
{
  pthread_rwlock_rdlock (&rwl);
  printf("LCD: Grabbed rwl\n");
  pthread_rwlock_unlock (&rwl);
  printf("LCD: released rwl\n");
}

void* Serial_thread (void* data)
{
  pthread_rwlock_rdlock (&rwl);
  printf("Serial: Grabbed rwl\n");
  pthread_rwlock_unlock (&rwl);
  printf("Serial: released rwl\n");
}


int main(int argc, char const *argv[])
{
  pthread_t incTid, LCDTid, SerialTid;
  pthread_rwlock_init (&rwl, NULL);

  pthread_create(&incTid, NULL, Inc_thread, NULL);
  pthread_create(&LCDTid, NULL, LCD_thread, NULL);
  pthread_create(&SerialTid, NULL, Serial_thread, NULL);

  pthread_join(incTid, NULL);
  pthread_join(LCDTid, NULL);
  pthread_join(SerialTid, NULL);

  return 0;
}
