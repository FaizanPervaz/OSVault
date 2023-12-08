#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void *take_input(void *arg)
{
    string *temp = (string *)arg;
    cin>>*temp;

    return (void*)temp;
}

void *find_ascii(void *arg)
{
    string *temp = (string *)arg;
    for(int i=0;i<temp->length();i++)
    {
        int ascii = (int)temp->at(i);
        if(ascii>=65 && ascii<=90)
        {
            ascii+=32;
        }
        else if(ascii>=97 && ascii<=122)
        {
            ascii-=32;
        }
        cout<<(int)ascii;
    }
    return NULL;
}

void * reverse_string(void * arg)
{
    string *temp = (string *)arg;
    for(int i=temp->length()-1;i>=0;i--)
    {
        cout<<temp->at(i);
    }
    return NULL;
}

void *check_palindrome(void * arg )
{
    string *temp = (string *)arg;
    string temp2;
    string temp3;
    for(int i=0; i<temp->length();i++)
    {
        temp2+=temp->at(i);
    }
    for(int i=temp->length()-1;i>=0;i--)
    {
        temp3+=temp->at(i);
    }

    if(temp2==temp3)
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not a palindrome"<<endl;
    }

    return NULL;
}

int main()
{
    pthread_t threads2;
    pthread_t threads3;
    pthread_t threads4;

    string temp;
    cout<<"Enter String"<<endl;
    cin>>temp;
    
    pthread_create(&threads2,NULL,find_ascii,(void*) &temp);
    cout<<endl;
    pthread_join(threads2,NULL);
    
    pthread_create(&threads3,NULL,reverse_string,(void*) &temp);
    cout<<endl;
    pthread_join(threads3,NULL);

    pthread_create(&threads4,NULL,check_palindrome,(void*) &temp);
    cout<<endl;

    pthread_join(threads4,NULL);

    
    pthread_exit(NULL);
}