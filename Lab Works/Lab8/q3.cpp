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
    pthread_cancel(tid);

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);

    pthread_setcancelstate(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
}