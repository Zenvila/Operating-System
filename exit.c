#include <stdio.h>
#include <stdlib.h>
void anotherExit();
int main()
{
int num;
printf("Enter a Number: ");
scanf("%i", &num);
if (num>25)
{
printf("exit 1\n");
exit(1);
}
else
anotherExit();
}
void anotherExit()

{
printf("Exit 2\n");
exit(1);
}
