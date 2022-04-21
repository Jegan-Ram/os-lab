#include <stdio.h>
#include <stdlib.h>

int semaphore = 1;
int balance = 0;

void producer()
{
    --semaphore;
    balance+=5000;
    printf("\nBalance %d\n",balance);
    ++semaphore;
}

void consumer()
{
    --semaphore;
    balance-=2000;
    printf("\nBalance %d\n",balance);
    ++semaphore;
}
 
int main()
{
    int n, i,flag=1;
    while(flag){
    printf("\n1. Press 1 to deposit money as X\n2. Press 2 to withdraw money as Y\n3. Press 3 for Exit\n"); 
    printf("\nEnter your choice:");
    scanf("%d",&n);
        switch (n) {
        case 1:
 
            if (semaphore == 1) {
                producer();
            }
            break;
 
        case 2:

            if ((semaphore == 1) && (balance > 0)) {
                consumer();
            }
            else {
                printf("\nBalance is empty!\n");
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
