#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void *thread_function(void *arg)
{
    sem_wait(&semaphore);
    printf("Thread %ld is accessing the resource.\n", (long)arg);
    sleep(2);
    printf("Thread %ld is done using the resource.\n", (long)arg);
    sem_post(&semaphore);
}

int main()
{
    pthread_t threads[5];
    sem_init(&semaphore, 0, 3);
    for (long i = 0; i < 5; i++)
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    for (int i = 0; i < 5; i++)
        pthread_join(threads[i], NULL);
    sem_destroy(&semaphore);
    return 0;
}
