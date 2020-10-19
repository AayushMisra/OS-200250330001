#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int id;

    id=fork();
    printf("ID is %d",&id);

    if(id==0){
        printf("In child process");
    }
    else
    {
        printf("In parent process");
    }

    return 0;
}