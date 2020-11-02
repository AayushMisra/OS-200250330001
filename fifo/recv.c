#include<stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    unsigned int rbuff[12];
    int fd,result;
    
    mkfifo("pipe",S_IWUSR | S_IRUSR);
    mkfifo("res",S_IWUSR | S_IRUSR);
  
    fd=open("pipe", O_RDONLY);
    read(fd,rbuff,12);
    close(fd);

    result=rbuff[0]+rbuff[1];

    fd=open("res", O_WRONLY);
    write(fd,&result,4);
    close(fd);
  
    return 0;
} 
