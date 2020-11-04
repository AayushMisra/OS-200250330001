#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    pid_t id;
    unsigned char rbuff[12];
    int pfd[2];

    pipe(pfd);

    id=fork();

    if(id==0){
        printf("In child process\n");
        read(pfd[0],rbuff,128);
        printf("Value received: %s\n",rbuff);
        close(pfd[0]);
    }
    else
    {
        printf("In parent process\n");
        write(pfd[1],"cdac\n",5);
        close(pfd[1]);
    }

    return 0;
}