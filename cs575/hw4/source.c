#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_WRITER_THREADS 2
#define NUM_READER_THREADS 3

int count;
int reader_count;
pthread_mutex_t write_mutex;
pthread_mutex_t read_mutex;

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
    pthread_mutex_lock(&write_mutex);

    int my_count = count;
    my_count = my_count + 1;

    printf("Writer %d wants to update count\n", my_data->number);
  
    sleep(my_data->sleep);

    count = my_count;

    printf("Writer %d update count to %d\n", my_data->number, count);

    pthread_mutex_unlock(&write_mutex);

    sleep(my_data->sleep);
  }

  pthread_exit(NULL);
}// writer

void*
reader(void* threadarg)
{
  struct thread_data* my_data;
  my_data = (struct thread_data*) threadarg;

  int loop;
  for (loop = 0; loop < my_data->iterations; loop++) {
    printf("Reader %d wants to read %d\n", my_data->number, count);
    
    pthread_mutex_lock(&read_mutex);
    reader_count++;
    if (1 == reader_count) {
      pthread_mutex_lock(&write_mutex);
    }
    pthread_mutex_unlock(&read_mutex);

    sleep(my_data->sleep);

    printf("Reader %d reads count as %d\n", my_data->number, count);

    pthread_mutex_lock(&read_mutex);
    reader_count--;
    if (0 == reader_count) {
      pthread_mutex_unlock(&write_mutex);
    }
    pthread_mutex_unlock(&read_mutex);

    sleep(my_data->sleep);
  }

  pthread_exit(NULL);
}// reader

int
main(int argc, char* argv[])
{
  printf("Start...\n");

  count = 0;
  reader_count = 0;

  struct thread_data write_data[NUM_WRITER_THREADS];
  struct thread_data read_data[NUM_READER_THREADS];

  pthread_t write_threads[NUM_WRITER_THREADS];
  pthread_t read_threads[NUM_READER_THREADS];
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  pthread_mutex_init(&read_mutex, NULL);
  pthread_mutex_init(&write_mutex, NULL);

  int t;
  for (t = 0; t < NUM_WRITER_THREADS; t++) {
    write_data[t].number = t;
    write_data[t].iterations = (t + 4);
    write_data[t].sleep = ((t % 2 == 0) ? 3 : 1);

    printf("Writer no. %d will loop for %d times, sleeping %dsec.\n",
           write_data[t].number,
           write_data[t].iterations,
           write_data[t].sleep);
  
    pthread_create(&write_threads[t], &attr, writer, (void *) &write_data[t]);
  }

  for (t = 0; t < NUM_READER_THREADS; t++) {
    read_data[t].number = t;
    read_data[t].iterations = (t + 4);
    read_data[t].sleep = ((t % 2 == 0) ? 1 : 2);

    printf("Reader no. %d will loop for %d times, sleeping %dsec.\n",
           read_data[t].number,
           read_data[t].iterations,
           read_data[t].sleep);
    
    pthread_create(&read_threads[t], &attr, reader, (void *) &read_data[t]);
  }
 
  for (t = 0; t < NUM_WRITER_THREADS; t++) {
    pthread_join(write_threads[t], NULL);
  }

  for (t = 0; t < NUM_READER_THREADS; t++) {
    pthread_join(read_threads[t], NULL);
  }

  printf("All threads finished, global count is %d\n", count);

  pthread_exit(NULL);
}// main
