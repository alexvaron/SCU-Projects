//Alex Varon
//Lab 5 Step 3
//10/25/20
//This code demonstrates producer and consumer issue using semaphores

#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty=3,x=0;
 
int main()
{
    int n;
    void producer();
    void consumer();
    int waitFor(int);
    int signalFor(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mutex==1)&&(empty!=0))
                        producer();
                    else
                        printf("Buffer is full!!");
                    break;
            case 2:    if((mutex==1)&&(full!=0))
                        consumer();
                    else
                        printf("Buffer is empty!!");
                    break;
            case 3:
                    exit(0);
                    break;
        }
    }
    
    return 0;
}
 
int waitFor(int s)
{
    return (--s);
}
 
int signalFor(int s)
{
    return(++s);
}
 
void producer()
{
    mutex=waitFor(mutex);
    full=signalFor(full);
    empty=waitFor(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex=signalFor(mutex);
}
 
void consumer()
{
    mutex=waitFor(mutex);
    full=waitFor(full);
    empty=signalFor(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signalFor(mutex);
}
