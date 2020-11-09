#include<stdio.h>
#include <pthread.h>
#include<unistd.h>
#include <semaphore.h>

int var=0;
sem_t sem_in, sem_out;

void * print(void *arg){
    while(1){
        sem_wait(&sem_out);

        printf("%d\n",var);

        sem_post(&sem_in);
    }
}

void * scan(void *arg){
    while(1){
        sem_wait(&sem_in);
    
        scanf("%d",&var);

        sem_post(&sem_out);
    }
}

int main(){

    pthread_t tid_sc, tid_pr;

    sem_init(&sem_in,0,1);
    sem_init(&sem_out,0,0);
    
    pthread_create(&tid_pr,NULL,print,NULL);    
    pthread_create(&tid_sc,NULL,scan,NULL);

    pthread_join(tid_pr,NULL);
    pthread_join(tid_sc,NULL);

    sem_destroy(&sem_in);
    sem_destroy(&sem_out);

    return 0;
}