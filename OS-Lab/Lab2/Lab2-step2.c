//Alex Varon
//9/30/20
//Lab 2 - step 6
//Description: The lab creates parent and child processes.

#include <stdio.h> /*printf, stderr*/
#include <sys/types.h> /*pid_t*/
#include <unistd.h> /*fork*/
#include <stdlib.h> /*atoi*/
#include <errno.h> /*errno*/
#include <pthread.h>

/*main function with command-line arguments to pass */


struct struc{
    int num;
    int n;
};

//part 6
void *fun2 (void *arg){
    struct struc *q = (struct struc*)arg;
    int num = q->num;
    int n = q->n;
    for (int i = 0; i < num; i++){
        printf("\t \t \t Process in second thread %d \n", i);
    }
 }
void *fun1 (void *arg) {
   struct struc *q = (struct struc*)arg;
   int num = q->num;
   int n = q->n;
   for (int i = 0; i < num; i++){
       printf("\t \t \t Process in first thread %d \n", i);
       usleep(n);
   }
}

              
 //the main function for two thread
int main (int argc, char *argv[]) {
    pid_t pid;
    int i, n = atoi(argv[1]);
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1){
        fprintf(stderr, "Can't fork, error %d\n", errno);
    }
    pthread_t p, p1;
    struct struc st, st1;
    st.num = 100;
    st.n = n;
    st1.num = 100;
    st1.n = n;
    pthread_create (&p, NULL, fun1, &st);
    pthread_create (&p1, NULL, fun2, &st1);
    pthread_join (p, NULL);
    pthread_join (p1, NULL);
    return 0;
}
