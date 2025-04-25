#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define NUM_CHILDREN 3
#define LOG_FILE "pmms.log"

pid_t child_pids[NUM_CHILDREN];
FILE *log_file;
int running = 1;
int paused_flags[NUM_CHILDREN] = {0, 0, 0};

void log_message(const char *message) {
    time_t now = time(NULL);
    char time_str[30];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(log_file, "[%s] %s\n", time_str, message);
    fflush(log_file);
    printf("%s\n", message);
}

void child_sigusr1_handler(int sig) {
    static int paused = 0;
    paused = !paused;
    if (paused) {
        printf("[Child %d] Paused...\n", getpid());
    } else {
        printf("[Child %d] Resumed...\n", getpid());
    }
    signal(SIGUSR1, child_sigusr1_handler);
}

void child_sigterm_handler(int sig) {
    printf("[Child %d] Terminating gracefully.\n", getpid());
    exit(0);
}

void child_process(int child_id) {
    signal(SIGUSR1, child_sigusr1_handler);
    signal(SIGTERM, child_sigterm_handler);
    static int paused = 0;
    printf("[Child %d] Process started\n", getpid());
    while (1) {
        if (!paused) {
            printf("[Child %d] Active...\n", getpid());
        }
        sleep(3);
    }
    exit(0);
}

void parent_sigint_handler(int sig) {
    char message[100];
    sprintf(message, "[Parent] Received SIGINT. Terminating all children.");
    log_message(message);
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (child_pids[i] > 0) {
            kill(child_pids[i], SIGTERM);
        }
    }
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (child_pids[i] > 0) {
            waitpid(child_pids[i], NULL, 0);
        }
    }
    log_message("[Parent] All children terminated. Exiting now.");
    fclose(log_file);
    exit(0);
}

int main() {
    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return 1;
    }
    log_message("=== PMMS Started ===");
    signal(SIGINT, parent_sigint_handler);
    printf("Parent PID: %d\n", getpid());
    for (int i = 0; i < NUM_CHILDREN; i++) {
        child_pids[i] = fork();
        if (child_pids[i] == -1) {
            perror("Fork failed");
            exit(1);
        } else if (child_pids[i] == 0) {
            child_process(i);
        } else {
            char message[100];
            sprintf(message, "[Parent] Created child process with PID: %d", child_pids[i]);
            log_message(message);
        }
    }
    int status;
    pid_t wpid;
    while ((wpid = wait(&status)) > 0) {
        for (int i = 0; i < NUM_CHILDREN; i++) {
            if (child_pids[i] == wpid) {
                char message[100];
                sprintf(message, "[Parent] Child process %d terminated", wpid);
                log_message(message);
                child_pids[i] = -1;
                break;
            }
        }
    }
    log_message("=== PMMS Terminated ===");
    fclose(log_file);
    return 0;
}
