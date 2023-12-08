#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t P1, P2;

    P1 = fork();

    if (P1 == 0) {
        printf("Child process P1 PID: %d",P1);
        printf("\n");
    } else {
        P2 = fork();

        if (P2 == 0) {
            printf("Child process P2 PID %d",P2);
            printf("\n");
        } else if(P2>0){
            printf("Parent process P PID %d",P2);
            printf("\n");
        }
    }

    return 0;
}

