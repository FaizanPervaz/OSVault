#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char *input = argv[1];
    int length = strlen(input);

    printf("Len: %d\n", length);

    return 0;
}
