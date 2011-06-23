#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_WRITER_THREADS 2
#define NUM_READER_THREADS 3

int count;
pthread_mutex_t mutex;

struct thread_data {
  int number;
  int iterations;
  int sleep;
};

void*
writer(void* threadarg)
{
  struct thread_data* my_data;
  my_data = (struct thread_data*) threadarg;

  int loop;
  for (loop = 0; loop < my_data->iterations; loop++) {
    pthread_mutex_lock(&mutex);

    int my_count = count;
    my_count = my_count + 1;

    printf("Writer %d wants to update count\n", my_data->number);
  
    sleep(my_data->sleep);

    count = my_count;

    printf("Writer %d update count to %d\n", my_data->number, count);

    pthread_mutex_unlock(&mutex);

    sleep(my_data->sleep);
  }

  pthread_exit(NULL);
}// writer

int
main(int argc, char* argv[])
{
  printf("Start...\n");

  pthread_t threads[NUM_WRITER_THREADS];
  struct thread_data data[NUM_WRITER_THREADS];

  pthread_mutex_init(&mutex, NULL);

  int t;
  for (t = 0; t < 2; t++) {
    data[t].number = t;
    data[t].iterations = (t + 4);
    data[t].sleep = ((t % 2 == 0) ? 3 : 1);

    printf("Thread no. %d will loop for %d times, sleeping %dsec.\n", data[t].number, data[t].iterations, data[t].sleep);
  
    pthread_create(&threads[t], NULL, writer, (void *) &data[t]);
  }
 
  for (t = 0; t < 2; t++) {
    pthread_join(threads[t], NULL);
  }

  printf("Both threads finished, global count is %d\n", count);

  pthread_exit(NULL);
}// main
