#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){


int pid=getpid();
int ppid=getppid();
char cmd[50];
printf("Here is the getpid %d \n",pid);
printf("Here is the getppip %d ",ppid);

snprintf(cmd,sizeof(cmd),   "pstree -p | grep %d" ,getppid()); 
system(cmd);

return 0;
}

