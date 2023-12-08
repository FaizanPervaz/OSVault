#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int a, b, c, d, e, f, h;
    int r1, r2, r3, r;
    int status;
    int v1, v2, v3;

    printf("Enter a :\n");
    scanf("%d", &a);
    printf("Enter b :\n");
    scanf("%d", &b);
    printf("Enter c :\n");
    scanf("%d", &c);
    printf("Enter d :\n");
    scanf("%d", &d);
    printf("Enter e :\n");
    scanf("%d", &e);
    printf("Enter f :\n");
    scanf("%d", &f);
    printf("Enter h :\n");
    scanf("%d", &h);

    pid_t child1 = fork();

    if (child1 == 0) {
        r1 = a + b;
        printf("Child 1 PID %d\n", getpid());  
        exit(r1);
    } else if (child1 > 0) {
        wait(&status);
        v1 = WEXITSTATUS(status);
    } else {
    }

    pid_t child2 = fork();

    if (child2 == 0) {
        r2 = c - d;
        printf("Child 2 PID %d\n", getpid());  
        exit(r2);
    } else if (child2 > 0) {
        wait(&status);
        v2 = WEXITSTATUS(status);
    } else {
    }

    pid_t child3 = fork();

    if (child3 == 0) {
        r3 = (e / f) * h;
        printf("Child 3 PID %d\n", getpid());  
        exit(r3);
    } else if (child3 > 0) {
        wait(&status);
        v3 = WEXITSTATUS(status);
    } else {
    }

    r = v1 + v2 + v3;  
    printf("Parent PID %d\n", getpid());
    printf("Result %d\n", r);

    sleep(1000);
    return 0;
}
