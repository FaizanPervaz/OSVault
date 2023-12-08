#include<iostream>
#include<ctime>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<cstring>
using namespace std;

int main()
{
    int n=0;
    srand((time(NULL)));
    int guessno=(rand()%100)+1;

    int A[2];
    int B[2];

    pipe(A);
    pipe(B);
    
    pid_t p = fork();

    if(p==0)
    {
        while(1)
        {
            close(A[1]);   //write
            close(B[0]);    //read

            if(n>=10)
            {
                cout<<"To Many Attempts"<<endl;
                break;
            }
            char guess[2];
            read(0, guess, sizeof(guess));
            
            // if(strcmp (guess[2],__int_to_char(guessno))==0)
            // {
            //     break;
            // }

            char guess1[2];
            cout<<"Player A Enter Number : "<<endl;
            cin>>guess1;

            write(1,guess1,strlen(guess1)+1);
            n++;
        }
    }
    else
    {
        while(1)
        {
            close(A[0]);   //read
            close(B[1]);    //write

            if(n>=10)
            {
                cout<<"To Many Attempts"<<endl;
                break;
            }
            char guess1[2];
            cout<<"Player B Enter Number : "<<endl;
            cin>>guess1;

            write(1,guess1,strlen(guess1)+1);

            char guess[2];
            read(0, guess, sizeof(guess));

            // if(strcmp (guess,__int_to_char(guessno))==0)
            // {
            //     break;
            // }
            n++;
        }
    }
}