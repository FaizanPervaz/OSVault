#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *a[], char *e[])
{
    //execl("/home/ayefaizy/Desktop/OS Labs/lab2/q2", "q2", NULL);
    //execlp("./q2", "q2.exe", NULL);
    //execv("/home/ayefaizy/Desktop/OS Labs/lab2/q2", a);
    //execvp("./q2", a);
    //execle("/home/ayefaizy/Desktop/OS Labs/lab2/q2", "q2", NULL, e);
    execve("/home/ayefaizy/Desktop/OS Labs/lab2/q2", a, e);
    return 0;
}