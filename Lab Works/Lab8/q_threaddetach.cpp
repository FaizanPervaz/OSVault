#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* thread1(void*)
{
    pthread_detach(pthread_self());
    for(int i=0;i<5;i++)
    {
        cout<<"*"<<endl;
        usleep(1);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread1,NULL);

    pthread_detach(tid);
    int r = pthread_join(tid,NULL);
    if(r==0)
    {
        cout<<"Thread joined successfully"<<endl;
    }
    else
    {
        cout<<"Thread not joined"<<endl;
    }
    pthread_exit(NULL);
}