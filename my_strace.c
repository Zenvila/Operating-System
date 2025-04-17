#include <sys/ptrace.h>        //ptrace used for   process tracing   debugging 
#include <sys/types.h>
#include <sys/wait.h>          //  syscall used  for to waith on child process
#include <sys/user.h>         // for  struct   which contain cpu regiter 
#include <sys/reg.h>         // for register constants 
#include <unistd.h>          //for fork and execvp
#include <stdio.h>
#include <stdlib.h>          // for exit





int main(int argc, char *argv[]) {
    // Check if program to trace is provided
    if (argc < 2) {
        printf("Usage: %s <program-to-trace>\n", argv[0]);
        return 1;
    }
    // above is the aurgument check if no target program is provided, the user is shown the correct usage and the program exits.

    // Create child process
    int pid=fork();

    if (pid<0) {
        perror("fork");
        return 1;
    }

    if (pid==0) {
        // Child:- allow tracing and run the target program
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(1);
    } else {
        // Parent:- trace the child
        int status;
        struct user_regs_struct regs;

        // Wait for child to stop initially
        waitpid(pid, &status, 0);

        while (1) {
            // Let child run until next syscall entry
            ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) break;

            // Get and print syscall number
            ptrace(PTRACE_GETREGS, pid, NULL, &regs);
            printf("System call number: %lld\n", regs.orig_rax);

            //  child run until syscall exit
            ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) break;

            // Get and print return value  by using the ptrace call 
            long ret = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * RAX, NULL);
            printf("Return value: %ld\n", ret);
        }

        printf("Child process exited.\n");
    }

    return 0;
}
