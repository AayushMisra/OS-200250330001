#include<stdio.h>
#include <pthread.h>
#include<unistd.h>
#include <semaphore.h>

int count=0;
sem_t count_sem;

void * increment(void *arg){
    sleep(1);
    for(int i=1;i<10;i++){
        sem_wait(&count_sem);

        count++;
        printf("Inc thread: %d\n",count);

        sem_post(&count_sem);
    }
}

void * decrement(void *arg){
    for(int i=1;i<10;i++){
        sem_wait(&count_sem);

        count--;
        printf("Dec thread: %d\n",count);

        sem_post(&count_sem);
        sleep(1);
    }
}

int main(){

    pthread_t tid_inc, tid_dec;

    sem_init(&count_sem,0,1);
    
    pthread_create(&tid_inc,NULL,increment,NULL);
    pthread_create(&tid_dec,NULL,decrement,NULL);

    pthread_join(tid_inc,NULL);
    pthread_join(tid_dec,NULL);

    sem_destroy(&count_sem);

    return 0;
}