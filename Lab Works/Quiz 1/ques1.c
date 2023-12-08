#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t P1, P2,P3,P4,P5,P6;

    P1 = fork();

    if (P1 == 0) {
        printf("Child process P2 PID: %d",getpid());
        printf("\n");

        P4 = fork();
        if(P4==0)
        {
            printf("Child process P4 PID: %d",getpid());
            printf("\n");

            P6 = fork();
            if(P6==0)
            {
                printf("Child process P6 PID: %d",getpid());
                printf("\n");
            }

        }

    } else {
        P3 = fork();

        if (P3 == 0) {
            printf("Child process P3 PID %d",getpid());
            printf("\n");

            P5 = fork();
            if(P5==0)
            {
                printf("Child process P5 PID %d",getpid());
                printf("\n");
            }


        } else if(P3>0){
            printf("Parent process P1 PID %d",getpid());
            printf("\n");
        }
    }

    sleep(1000);
    return 0;
}
