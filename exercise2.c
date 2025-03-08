 

#include <stdio.h> 

#include <unistd.h> 

#include <stdlib.h> 

  

int main() { 

    printf("Process started. PID: %d, Parent PID: %d\n", getpid(), getppid()); 

  

    // First fork - Creates 1 new process Total: 2 

    fork(); 

  

 // As  same 2  and previous 2    = 4 

 fork(); 

  

// As  same 2  and previous 4  = 6 

    fork(); 

  

    // here we add sleep to check the proccess using ps au  

    sleep(60); 

  

    return 0; 

} 
