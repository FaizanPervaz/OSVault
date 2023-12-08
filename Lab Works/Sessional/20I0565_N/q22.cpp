#include<iostream>
#include<ctime>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<cstring>
using namespace std;

int main()
{
    pid_t p = fork();

    if(p==0)
    {
        cout<<"Child 1 : "<<getpid() <<endl;
        pid_t p1= fork();
        if(p1==0)
        {
            // cout<<"Child 2 : "<<getpid()<<endl;
            // if(execlp("ls","ls",NULL)==-1)
            // {
            //     cout<<"child failed"<<endl;
            // }
            char* command = "ls";
            char* argv[] ={"ls","-l",NULL};
            execvp(command,argv);
        }
    }
    else
    {
        wait(NULL);
        cout<<"Parent P : "<<getpid()<<endl;
        cout<<"child successful"<<endl;
    }
}