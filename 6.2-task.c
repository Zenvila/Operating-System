#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pid;       // For storing fork() return
    int pfd[2];    // For pipe file descriptors
    char aString[20] = "Empty"; // Temporary storage initialized with some value

    pipe(pfd);  // Create pipe

    pid = fork(); // Create child process

    if (pid == 0) {  // Child process
        close(pfd[0]);  // Close unused read end
        write(pfd[1], "Hello", 5); // Write onto pipe
        close(pfd[1]);  // Close write end after writing
    } 
    else {  // Parent process
        close(pfd[1]);  // Close unused write end

        printf("Before read(): aString = %s\n", aString); // Display before read

        read(pfd[0], aString, 5); // Read from pipe
        aString[5] = '\0'; // Null terminate the string

        printf("After read(): aString = %s\n", aString); // Display after read

        close(pfd[0]);  // Close read end
    }

    return 0;
}

