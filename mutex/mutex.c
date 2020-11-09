#include<stdio.h>
#include <pthread.h>
#include<unistd.h>

int count=0;
pthread_mutex_t count_mutex;
//pthread_mutexattr_t count_mutex_attr;

void * increment(void *arg){
    sleep(1);
    for(int i=1;i<10;i++){
        pthread_mutex_lock(&count_mutex);

        count++;
        printf("Inc thread: %d\n",count);

        pthread_mutex_unlock(&count_mutex);
    }
}

void * decrement(void *arg){
    for(int i=1;i<10;i++){
        pthread_mutex_lock(&count_mutex);
   
        count--;
        printf("Dec thread: %d\n",count);

        pthread_mutex_unlock(&count_mutex);
        sleep(2);
    }
}

int main(){

    pthread_t tid_inc, tid_dec;

    pthread_mutex_init(&count_mutex,NULL);
   // pthread_mutexattr_init(&count_mutex_attr);

    pthread_create(&tid_inc,NULL,increment,NULL);
    pthread_create(&tid_dec,NULL,decrement,NULL);

    pthread_join(tid_dec,NULL);
    pthread_join(tid_inc,NULL);
    
    pthread_mutex_destroy(&count_mutex);

    return 0;
}