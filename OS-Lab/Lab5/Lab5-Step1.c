//Alex Varon
//Lab 5 Step 1
//10/25/20
//This code demonstrates threads entering and exiting 

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 10
pthread_t threads[NTHREADS];
sem_t *mutex; 

void* go(void* arg) { 
    sem_wait(mutex); //enter
    printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section
    sleep(1);
    sem_post(mutex); //exit
    return (NULL);
}

int main() { 
    mutex = sem_open("mutex", O_CREAT, 0644, 1);
    static int i;
    for (i = 0; i < NTHREADS; i++)
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
        printf("\t\t\tThread %d returned \n", i);
    }
    printf("Main thread done.\n");
    sem_unlink("mutex");
    return 0;
}

