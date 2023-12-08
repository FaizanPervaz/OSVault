#include<iostream>
#include<ctime>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<cstring>
#include<signal.h>
using namespace std;

int main()
{
    int x,o;

    char board[9];

    pid_t p = fork();

    while(1)
    {
        
        if(p==0)
        {
            cout<<"X: Enter Position to add"<<endl;
            cout<<"--1--|--2--|---3--\n";
            cout<<"--4--|--5--|---6--\n";
            cout<<"--7--|--8--|---9--\n";

            cin>>x;

            if(x==1)
            {
                board[0]='X';
            }
            if(x==2)
            {
                board[1]='X';
            }
            if(x==3)
            {
                board[2]='X';
            }
            if(x==4)
            {
                board[3]='X';
            }
            if(x==5)
            {
                board[4]='X';
            }
            if(x==6)
            {
                board[5]='X';
            }
            if(x==7)
            {
                board[6]='X';
            }
            if(x==8)
            {
                board[7]='X';
            }
            if(x==9)
            {
                board[8]='X';
            }

            if(board[0]=='X' && board[1]== 'X' && board[2]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[3]=='X' && board[4]== 'X' && board[5]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[6]=='X' && board[7]== 'X' && board[8]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[0]=='X' && board[3]== 'X' && board[6]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[1]=='X' && board[4]== 'X' && board[7]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[2]=='X' && board[5]== 'X' && board[8]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[0]=='X' && board[4]== 'X' && board[8]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[2]=='X' && board[4]== 'X' && board[6]=='X')
            {
                cout<<"X Won"<<endl;
                kill(p,SIGKILL);
            }
        }
        else
        {
            cout<<"O: Enter Position to add"<<endl;
            cout<<"--1--|--2--|---3--\n";
            cout<<"--4--|--5--|---6--\n";
            cout<<"--7--|--8--|---9--\n";

            cin>>o;

            if(o==1)
            {
                board[0]='o';
            }
            if(o==2)
            {
                board[1]='o';
            }
            if(o==3)
            {
                board[2]='o';
            }
            if(o==4)
            {
                board[3]='o';
            }
            if(o==5)
            {
                board[4]='o';
            }
            if(o==6)
            {
                board[5]='o';
            }
            if(o==7)
            {
                board[6]='o';
            }
            if(o==8)
            {
                board[7]='o';
            }
            if(o==9)
            {
                board[8]='o';
            }

            if(board[0]=='o' && board[1]== 'o' && board[2]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[3]=='o' && board[4]== 'o' && board[5]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[6]=='o' && board[7]== 'o' && board[8]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[0]=='o' && board[3]== 'o' && board[6]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[1]=='o' && board[4]== 'o' && board[7]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[2]=='o' && board[5]== 'o' && board[8]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[0]=='o' && board[4]== 'o' && board[8]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
            else if(board[2]=='o' && board[4]== 'o' && board[6]=='o')
            {
                cout<<"o Won"<<endl;
                kill(p,SIGKILL);
            }
        }
    }
}