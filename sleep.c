#include <stdio.h> 

#include <unistd.h> // For sleep() 

  

int main() { 

    for (int i = 10; i >= 0; i--) { 

        printf("%d\n", i); 

        sleep(1);  

    } 

    return 0; 

} 
