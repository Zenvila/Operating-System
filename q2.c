//   here is the five state of process code 


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
int i;
printf("Process PID %6d \t PPID %6d \n", getpid(), getppid());
for (i = 0; i<1; ++i)
{
if (fork()==0)
printf("Process PID %6d \t PPID %6d \n", getpid(), getppid());
}
return 0;
}


