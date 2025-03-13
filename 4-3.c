
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
char* get_timeStamp()
{
time_t now = time(NULL);
return asctime(localtime(&now));
}
int main(int argc, char* argv[])
{
char *filename = argv[1];
char *timeStamp = get_timeStamp();
int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
size_t length = strlen(timeStamp)-5;
write(fd, timeStamp, length);
close(fd);
return 0;
}

//Q1:
// 0666 here is the mode int
// open(pathname, flags, modes);
// accordign to the above statment   mode is the permission 
// int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
// here fd  is the file descriptor we create the new fd which is 3       


//Q2:
// here O_append is the  method to append the file like do not vaninsh the previous data  while instering new data 


//Q3:
// size_t length = strlen(timeStamp)-5 ;
 // when i run this using -5    it remove the  year    in the first one     without -5 it also  print  the  year also as well 

