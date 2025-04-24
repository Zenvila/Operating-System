#include <stdio.h>
#include <pthread.h>

struct thread_data
{
    int x;
    int y;
    int z;
};

void *print(void *threadArg)
{
    struct thread_data *my_data = (struct thread_data *)threadArg;
    printf("X: %d, Y: %d, Z: %d\n", my_data->x, my_data->y, my_data->z);
    return NULL;
}

int main(void)
{
    pthread_t tid;
    struct thread_data obj;

    obj.x = 1;
    obj.y = 2;
    obj.z = obj.x + obj.y;

    pthread_create(&tid, NULL, print, &obj);
    pthread_join(tid, NULL);

    return 0;
}

