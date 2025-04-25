#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


sem_t semaphore;
void *thread_function(void *arg)
{
sem_wait(&semaphore);
printf("Thread %ld is entering the critical section.\n", (long)arg);
sleep(1);
printf("Thread %ld is leaving the critical section.\n", (long)arg);
sem_post(&semaphore);
}
int main()
{
pthread_t threads[3];
sem_init(&semaphore, 0, 1);
for (long i = 0; i < 3; i++)
pthread_create(&threads[i], NULL, thread_function, (void*)i);
for (int i = 0; i < 3; i++)
pthread_join(threads[i], NULL);
sem_destroy(&semaphore);
return 0;
}
