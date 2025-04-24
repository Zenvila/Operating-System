#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int myGlobal = 0;
void *threadFunction()
{
int i, j;
for (i = 0; i<5; i++)
{
j = myGlobal;
j = j+1;
printf(".");
fflush(stdout);
sleep(1);
myGlobal = j;
}
}
int main()
{
pthread_t myThread;
int i;
pthread_create(&myThread, NULL, threadFunction, NULL);
for (i = 0; i < 5; i++)
{
myGlobal = myGlobal + 1;
printf("o");
fflush(stdout);
sleep(1);
}
pthread_join(myThread, NULL);
printf("\nMy Global Is: %d\n", myGlobal);
exit(0);
}
