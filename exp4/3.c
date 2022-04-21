#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int n1 = fork();
    int n2 = fork();
    int n3 = fork();  
     
    if (n1 > 0 && n2 > 0 && n3 > 0) {
        printf("parent\n");
        printf("%d %d %d\n", n1, n2, n3);
        printf(" my id is %d \n", getpid());
    }
    else if (n1 == 0 && n2 > 0 && n3 > 0)
    {
        sleep(3);
        printf("First child\n");
        printf("%d %d %d\n", n1, n2, n3);
        printf("my id is %d  \n", getpid());
    }
    else if (n1 > 0 && n2 == 0 && n3 > 0)
    {
        sleep(6);
        printf("Second child\n");
        printf("%d %d %d\n", n1, n2, n3);
        printf("my id is %d  \n", getpid());
    }
       else if (n1 > 0 && n2 > 0 && n3 == 0)
    {    sleep(9);
  
        printf("Third child\n");
        printf("%d %d %d\n", n1, n2, n3);
        printf("my id is %d  \n", getpid());
    }
       else if (n1 == 0 && n2 == 0 && n3 > 0)
    {    sleep(12);
  
        printf("Fourth child\n");
        printf("%d %d %d\n", n1, n2, n3);
        printf("my id is %d  \n", getpid());
    }
    return 0;
}