#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* thread1(void*)
{
    // pthread_detach(pthread_self());
    for(int i=0;i<5;i++)
    {
        cout<<"*"<<endl;
        usleep(10000);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

    pthread_create(&tid,&attr,thread1,NULL);

    pthread_attr_destroy(&attr);

    usleep(99999);
}