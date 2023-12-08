#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]) 
{
    char input[256]; 

    //input reading code in c taken from geeks for geeks
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("fgets");
        exit(1);
    }

    size_t input_len = strlen(input);
    if (input_len > 0 && input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
    }
    //

    pid_t capatalize = fork();
    if (capatalize == 0) {
        execl("./cap", "cap", input, NULL);
    } else {
        wait(NULL);

        pid_t reverse = fork();
        if (reverse == 0) {
            execl("./rev", "rev", input, NULL);
        } else {
            wait(NULL);

            pid_t length = fork();
            if (length == 0) {
                execl("./len", "len", input, NULL);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}
