#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
if (argc != 2)
{
printf("Error: Run like this: ");
printf("%6s name-of-existing-file\n", argv[0]);
return 1;
}
char *path = argv[1];
int fd = open(path, O_RDONLY);
if (fd == -1)
{
printf("File does not exist\n");
return 1;
}
char buffer[200];
read(fd, buffer, sizeof(buffer)-1);
printf("Contents of File are:\n");
printf("%s\n", buffer);
close(fd);
return 0;
}




// first i run the file     but it shows file does not exist    but i run   with the previous file that we have create it shows the time which we have store in the previous  file 

