#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* mythread(void *ptr)
{
    cout<<"Pervaz"<<endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, mythread, NULL);
    cout<<"Faizan"<<endl;
    cout<<pthread_self()<<endl;
    pthread_exit(NULL);
}