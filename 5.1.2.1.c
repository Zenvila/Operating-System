#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){

int pid=fork();


if(pid==0){
	sleep(120);
}
else{
	sleep(5);
	kill(pid,SIGTERM);
}


return 0;
}

// sending signal form the parent process 
//
