#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myGlobal = 0;
pthread_mutex_t myMutex;

void *threadFunction()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&myMutex);
        j = myGlobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myGlobal = j;
        pthread_mutex_unlock(&myMutex);
    }
    return NULL;
}

int main()
{
    pthread_t myThread;
    int i;

    pthread_create(&myThread, NULL, threadFunction, NULL);

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&myMutex);
        myGlobal = myGlobal + 1;
        pthread_mutex_unlock(&myMutex);
        printf("o");
        fflush(stdout);
        sleep(1);
    }

    pthread_join(myThread, NULL);
    printf("\nMy Global Is: %d\n", myGlobal);
    return 0;
}

