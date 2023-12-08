#include<iostream>
#include <pthread.h>
#include<unistd.h>

using namespace std;

#define SIZE 1000

int a[SIZE][SIZE];
int b[SIZE][SIZE];
int r[SIZE][SIZE];

class MatrixInfo{
public:
    int start;
    int end;
};

void *mat_mul(void *arg) 
{
    MatrixInfo *args = (MatrixInfo *)arg;
    for (int i = args->start; i < args->end; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            r[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) 
            {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[i][j] = rand() % 10; 
            b[i][j] = rand() % 10;
        }
    }

    pthread_t t_id[4];
    MatrixInfo args[4];

    for (int i = 0; i < 4; ++i) 
    {
        args[i].start = i * 1000/4;
        args[i].end = args[i].start + 1000/4;
        pthread_create(&t_id[i], NULL, mat_mul, (void *)&args[i]);
    }

    for (int i = 0; i < 4; ++i) {
        pthread_join(t_id[i], NULL);
    }

    cout<<"Resultant : "<<endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }

    pthread_exit(NULL);
    return 0;
}
