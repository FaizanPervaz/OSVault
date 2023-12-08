#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define ARR_SIZE 100

pthread_t tid[4];
int no_to_find;
int arr[ARR_SIZE];

void *thread_function(void *arg)
{
    int *temp = (int *)arg;
    int a = *temp * (ARR_SIZE / 4);
    int b = a + (ARR_SIZE / 4);
    
    for (int i = a; i < b; i++)
    {
        if (arr[i] == no_to_find)
        {
            cout <<"Thread Used To Find : "<< *temp+1 << endl;
            break;
        }
    }
    pthread_exit(NULL);
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }

    int n = 4;
    int t_no[n];
    for (int i = 0; i < n; i++)
    {
        t_no[i] = i;
    }

    cout << "Input Number : ";
    cin >> no_to_find;

    if(no_to_find>100)
    {
        cout<<"Number not in range"<<endl;
        return 0;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for (int i = 0; i < n; i++)
    {
        pthread_create(&tid[i], &attr, thread_function, (void *)&t_no[i]);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_exit(NULL);
}

#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

void* input(void* arg){
    int number,temp=0;
    int temp2;
    cout<<"Thread#1 Processing"<<endl;
    cout<<"Enter the number: ";
    cin>>number;
    temp2=number;
    while(number>=1){
        temp+=number%10;
        temp=temp*10;
        number=number/10;
    }
    temp=temp/10;
    if(temp2==temp){
        cout<<"\t"<<temp2<<" is a palindrome."<<endl;
    }
    else{
        cout<<"\t"<<temp2<<" is not palindrome."<<endl;
    }
    int* value = &temp2;
    return (void*)value
}

void* display(void* arg){
    int *number=(int *)arg;
    int temp=1;
    cout<<*number;
    if((*number)%2==0){
        cout<<"\t"<<*number<<" is a even number."<<endl;
    }
    else{
        while(temp<20){
            cout<<temp<<" ";
            temp+=2;
        }
        cout<<endl;
    }

    return NULL;
}


int main(){
    void* exit_number;
    pthread_t thr1,thr2;
    pthread_create(&thr1,NULL,input,NULL);
    pthread_join(thr1,&exit_number);
    int* num = (int*)exit_number;
    
    pthread_create(&thr2,NULL,display,exit_number);
    pthread_join(thr2,NULL);
    exit(0);
}
