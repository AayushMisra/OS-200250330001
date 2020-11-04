#include<stdio.h>
#include <pthread.h>
#include<unistd.h>

int count=0;

void * increment(void *arg){
    for(int i=1;i<10;i++){
        count++;
        printf("Inc thread: %d\n",count);
    }
}

void * decrement(void *arg){
    for(int i=1;i<10;i++){
        count--;
        printf("Dec thread: %d\n",count);
    }
}

int main(){

    pthread_t tid;
    
    pthread_create(&tid,NULL,increment,NULL);
    pthread_create(&tid,NULL,decrement,NULL);

    pthread_join(tid,NULL);

    return 0;
}