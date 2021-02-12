//Alex Varon
//Lab 5 Step 4
//10/25/20
//This code demonstrates producer and consumer issue using condition variable

#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

int max, loops, numConsumers;
int * buffer;
int fillIndex, useIndex, count = 0;

/* Buffer Operations */

void put(int value) {
    buffer[fillIndex] = value;
    fillIndex = (fillIndex + 1) % max;
    count++;
}

int get() {
    int tmp = buffer[useIndex];
    useIndex = (useIndex + 1) % max;
    count--;
    return tmp;
}
/* Currently unsafe producer and consumer */
void * producer() {
    for (int i = 0; i < loops; i++) {
        put(i);
    }
}

void * consumer() {
    for (int i = 0; i < loops; i++) {
        int tmp = get();
        printf("%d", tmp);
    }
}


int main(int argc, char * argv[]) {
    /* Process arguments */
    max = atoi(argv[1]);
    int loops = atoi(argv[2]);
    numConsumers = atoi(argv[3]);

    buffer = malloc(sizeof(int)*max);
    pthread_t prods, cons[5];
    /* Create the producer */
    pthread_create(&prods, NULL, producer, NULL);
    /* Create the consumers */
    for (int i = 0; i < numConsumers; i++)
        pthread_create(&cons[i], NULL, consumer, NULL);
    pthread_join(prods, NULL);
    for (int j = 0; j < numConsumers; j++)
        pthread_join(cons[j], NULL);
    return 0;
}
