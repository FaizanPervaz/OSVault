#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char *input = argv[1];
    char *output;

    for (int i = 0; input[i]; i++) {
        output[i] = toupper(input[i]);
    }
    output[strlen(input)] = '\0';

    for (int i = 0; output[i]; i++) 
    {
        printf("%c", output[i]);
    }

    return 0;
}
