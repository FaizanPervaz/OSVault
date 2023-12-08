#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char *input = argv[1];
    int length = strlen(input);

    for (int i = length - 1; i >= 0; i--) {
        putchar(input[i]
    }
    putchar('\n');

    return 0;
}
