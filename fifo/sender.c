#include<stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    int a[10],fd;
    a[0]=10;
    a[1]=20;
    
    mkfifo("pipe", S_IWUSR | S_IRUSR);
    mkfifo("res", S_IWUSR | S_IRUSR);
 
    fd = open("pipe", O_WRONLY);
    write(fd,&a,8);
    close(fd);

    fd = open("res", O_RDONLY);
    read(fd,a,4);
    close(fd);

    printf("Result is %d\n",a[0]);

    return 0;
} 
