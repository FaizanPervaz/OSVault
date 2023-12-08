#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* mythread(void *arg)
{
    int * ptr = (int *)arg;
    cout<<5*(*ptr)<<endl;
    pthread_exit(NULL);
}

int main()
{
    int a=5;
    pthread_t tid;
    pthread_create(&tid, NULL, mythread, (void*) &a);
    cout<<"Faizan"<<endl;
    cout<<pthread_self()<<endl;
    pthread_exit(NULL);
}