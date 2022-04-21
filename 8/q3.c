#include <stdio.h>
#include <stdlib.h>

int semaphore = 1;
int stack = 0;
int empty = 10, x = 0;
 

void producer()
{
    --semaphore;
    ++stack;
    --empty;
    x++;
    printf("\nProducer produces item %d\n",x);
    ++semaphore;
}

void consumer()
{
    --semaphore;
    --stack;
    ++empty;
    printf("\nConsumer consumes item %d\n",x);
    x--;
    ++semaphore;
}
 
int main()
{
    int n, i,flag=1;
    while(flag){
    printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit\n"); 
    printf("\nEnter your choice:");
    scanf("%d",&n);
        switch (n) {
        case 1:
 
            if ((semaphore == 1) && (empty != 0)) {
                producer();
            }
 
            else {
                printf("\nBuffer is stack!\n");
            }
            break;
 
        case 2:

            if ((semaphore == 1) && (stack != 0)) {
                consumer();
            }
            else {
                printf("\nBuffer is empty!\n");
            }
            break;
 
        case 3:
            exit(0);
            break;
        default:
            flag=0;   
}
}
return 0;    
}
