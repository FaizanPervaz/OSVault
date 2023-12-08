#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;
int count = 0;
pthread_t tid[5];
void * counter(void *)
{
    char * status = "Hello";
    count++;
    cout<<count<<endl;
    pthread_exit((void*)status);
}
int main()
{
    void * status;

    for (int i=0;i<5;i++)
    {
        pthread_create(&tid[i], NULL, counter, NULL);
        pthread_join(tid[i], &status);
        cout<<(char *)status <<endl;
    }

    pthread_exit(NULL);
}