//Alex Varon
//Lab 5 Step 2
//10/25/20
//This code demonstrates threads entering and exiting but uses mutex locks

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t mutex; 

void* go(void* arg) {
    pthread_mutex_lock(&mutex); //enter
    printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section
    sleep(1);
    pthread_mutex_unlock(&mutex); //exit
    return (NULL);
}

int main() {
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NTHREADS; i++)   {
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
        printf("\t\t\tThread %d returned \n", i);
    }
    printf("Main thread done.\n");
    pthread_mutex_destroy(&mutex);
    return 0;
}
