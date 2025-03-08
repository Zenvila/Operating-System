#include <stdio.h>
#include <stdlib.h> 

void f3();  

int main() {
    f3();  
    exit(0);  
}

void f3() {
    printf("IN F3 : ");
    abort();  
	       }
