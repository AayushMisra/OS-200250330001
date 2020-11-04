#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t id;

    id=fork();
    printf("ID is %d\n",&id);

    if(id==0){
        printf("In child process\n");
    }
    else
    {
        printf("In parent process\n");
    }

    return 0;
}