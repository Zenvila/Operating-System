#include <unistd.h>
#include <stdio.h>

int main() {
    int p;
    p = fork(); // Create a new process

    printf("Job Done\n");
    sleep(120); // Both parent and child sleep for 120 seconds

    return 0;
}

