#include <fcntl.h>
#include <stdio.h>   
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
char *path = argv[1];
int fd = open(path, O_WRONLY | O_EXCL | O_CREAT);
if (fd == -1)
{
printf("Error: File not Created\n");
return 1;
}
return 0;
}

//Q1:
//     Here the size the of the file is  0    , bcz  there is nothing in this file . 

