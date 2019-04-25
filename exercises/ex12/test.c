#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "utils.h"

int counter = 0;

void *procreate(void *arg){
    if(counter > 3){
        printf("b ");
        pthread_exit(NULL);
    }
    pthread_t child;
    pthread_create(&child, NULL, procreate, NULL);
    printf("%d ", counter);
    counter++;
    pthread_join(child, NULL);
    printf("c ");
    pthread_exit(NULL);
}

int main(){
    printf("a ");
    procreate(NULL);
}
