#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 2

int count;
int flags[NUM_THREADS];
int turn;

struct thread_data {
  int number;
  int iterations;
  int sleep;
};

void*
runner(void* threadarg)
{
  struct thread_data* my_data;
  my_data = (struct thread_data*) threadarg;

  int i = my_data->number;
  int j = (my_data->number == 0) ? 1 : 0;

  int loop;
  for (loop = 0; loop < my_data->iterations; loop++) {
    flags[i] = 1;
    turn = j;
    while (flags[j] == 1 && turn == j);

    int my_count = count;
    my_count = my_count + 1;

    printf("Thread no. %d, loop %d, started with count of %d\n", my_data->number, loop, count);
  
    sleep(my_data->sleep);

    count = my_count;

    printf("Thread no. %d, loop %d, finished with count of %d\n", my_data->number, loop, count);

    flags[i] = 0;

    sleep(my_data->sleep);
  }

  pthread_exit(NULL);
}// runner

int
main(int argc, char* argv[])
{
  printf("Start...\n");

  pthread_t threads[NUM_THREADS];
  struct thread_data data[NUM_THREADS];

  int t;
  for (t = 0; t < 2; t++) {
    data[t].number = t;
    data[t].iterations = (t + 4);
    data[t].sleep = ((t % 2 == 0) ? 3 : 1);

    printf("Thread no. %d will loop for %d times, sleeping %dsec.\n", data[t].number, data[t].iterations, data[t].sleep);
  
    pthread_create(&threads[t], NULL, runner, (void *) &data[t]);
  }
 
  for (t = 0; t < 2; t++) {
    pthread_join(threads[t], NULL);
  }

  printf("Both threads finished, global count is %d\n", count);

  pthread_exit(NULL);
}// main
