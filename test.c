#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    close(fd);
    return 0;
}

