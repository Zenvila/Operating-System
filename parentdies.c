#include <unistd.h> 
#include<stdlib.h>
#include <stdio.h> 

int main() 

{ 

int i, pid; 

pid = fork(); 

if (pid > 0) // Parent 

{ 

sleep(2); 

exit(0); 

} 

else if (pid == 0) // Child 

{ 

for (i=0; i < 5; i++) { 

printf("My parent is %d\n", getppid()); 

sleep(1); 

} } } 
