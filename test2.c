#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];

    write(STDOUT_FILENO, "Chatbot: Hello! Type something (type 'exit' to quit).\n", 54);

    while (1) {
        write(STDOUT_FILENO, "You: ", 5);
        
        int bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (bytesRead <= 0) {
            write(STDOUT_FILENO, "Chatbot: Error reading input.\n", 30);
            break;
        }

        buffer[bytesRead - 1] = '\0'; // Remove newline character

        // Check exit condition
        if (strcmp(buffer, "exit") == 0) {
            write(STDOUT_FILENO, "Chatbot: Goodbye!\n", 18);
            break;
        }

        // Simple responses based on input
        if (strcmp(buffer, "hello") == 0) {
            write(STDOUT_FILENO, "Chatbot: Hi there!\n", 19);
        } else if (strcmp(buffer, "how are you") == 0) {
            write(STDOUT_FILENO, "Chatbot: I'm just a bot, but I'm fine! 😊\n", 41);
        } else {
            write(STDOUT_FILENO, "Chatbot: I don't understand that.\n", 34);
        }
    }

    return 0;
}

