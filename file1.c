#include <unistd.h> 

#include <stdio.h> // Library used for printf() 

  

int main() 

{ 

    int p; 

    p = fork(); 

    printf("Job Done\n"); 
    printf("Value of P is %d\n", p);

} 
