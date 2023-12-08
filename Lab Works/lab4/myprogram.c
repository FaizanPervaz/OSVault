#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec call\n");
    execl("/path/to/myprogram", "myprogram", "arg1", "arg2", NULL);
    printf("After exec call\n");  // This line will never be reached
    return 0;
}
