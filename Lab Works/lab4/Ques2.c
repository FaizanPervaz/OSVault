#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    char str[256];
    printf("Enter the command: ");
    scanf("%s", str);

    pid_t p=fork();
    if(p==0)
    {
        if(strcmp(str,"ls")==0)
        {
            execl("/bin/ls", "ls", NULL);
        }
        else if(strcmp(str,"pwd")==0)
        {
            execlp("pwd","pwd", NULL);
        }
        else if(strcmp(str,"date")==0)
        {
            execle("/bin/date", "date", NULL, NULL);
        }
        else if (strcmp(str, "cal") == 0) 
        {
            execlp("cal", "cal", NULL);
        }
        else if(strcmp(str,"exit")==0)
        {
            execl("bin/exit", "exit", NULL);
            printf("Exitted\n");
        }
        else
        {
            printf("Command not found\n");
        }
        wait(NULL);
    }
    

}