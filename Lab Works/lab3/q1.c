#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t P1, P2, P3;

    P1 = fork();

    if (P1 == 0) {
        printf("Child process P1 PID: %d",getpid());
        printf("\n");

        P2 = fork();

        if(P2==0)
        {
            printf("Child process P2 PID: %d",getpid());
            printf("\n");

            P3 = fork();

            if(P3==0)
            {
                printf("Child process P3 PID: %d",getpid());
                printf("\n");
            }   
        }
    } else 
        {
            printf("Parent process P PID %d",getpid());
            printf("\n");
        }

    return 0;
}

