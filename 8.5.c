#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct fib_arg {
    int n;
    long result;
};

void *fib_thread(void *arg_ptr)
{
    struct fib_arg *arg = (struct fib_arg *)arg_ptr;

    if (arg->n <= 0)
        arg->result = 0;
    else if (arg->n == 1)
        arg->result = 1;
    else {
        pthread_t t1, t2;
        struct fib_arg a1 = { .n = arg->n - 1 };
        struct fib_arg a2 = { .n = arg->n - 2 };

        pthread_create(&t1, NULL, fib_thread, &a1);
        pthread_create(&t2, NULL, fib_thread, &a2);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        arg->result = a1.result + a2.result;
    }
    return NULL;
}

int main(void)
{
    int find = 40;
    pthread_t top;
    struct fib_arg top_arg = { .n = find };

    pthread_create(&top, NULL, fib_thread, &top_arg);
    pthread_join(top, NULL);

    printf("Element No. %d in series is: %ld\n", find, top_arg.result);
    return 0;
}

