#include <stdio.h>
#include <pthread.h>

pthread_barrier_t barrier;


void *Serial (void *data)
{
  printf("Initislizing Serial\n");
  sleep(3);
  pthread_barrier_wait(&barrier);
  printf("Sending data to serial\n");
}
void *LCD (void *data)
{
  printf("Initislizing LCD\n");
  sleep(4);
  pthread_barrier_wait(&barrier);
  printf("Sending data to LCD\n");
}
void *Sensor (void *data)
{
  printf("Initislizing \n");
  sleep(5);
  pthread_barrier_wait(&barrier);
  printf("Sending data to Sensor\n");
}

int main(int argc, char const *argv[])
{
  pthread_t Serial_thread, LCD_thread, Sensor_thread;

  pthread_barrier_init (&barrier, NULL, 3);

  pthread_create(&Serial_thread, NULL, Serial, NULL);
  pthread_create(&LCD_thread, NULL, LCD, NULL);
  pthread_create(&Sensor_thread, NULL, Sensor, NULL);

  pthread_join(Serial_thread, NULL);
  pthread_join(LCD_thread, NULL);
  pthread_join(Sensor_thread, NULL);

  pthread_barrier_destroy(&barrier);

  return 0;
}
