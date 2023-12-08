#include<sys/shm.h>
#include<sys/ipc.h>
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<cstring>

using namespace std;
int main()
{   
    void *shared_memory;
    char buff[100];
    int shmid;

    shmid = shmget((key_t)1234, 1024, 0666|IPC_CREAT);
    if(shmid == -1)
    {
        cout<<"shmget failed"<<endl;
        exit(0);
    }
    cout<<"ShmID : "<<shmid<<endl;
    
    shared_memory = shmat(shmid, NULL, 0);

    cout<<"Process attached at : "<<shared_memory<<endl;

    cout<<"Enter data to write : ";
    fgets(buff, 100, stdin);

    strcpy((char*)shared_memory, buff);

    cout<<"Data written in shared memory : "<<(char*)shared_memory<<endl;
}