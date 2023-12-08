#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int numberOfStudents, numberOfPieces, pizzaCount = 0;
int checkpieces=0;
pthread_mutex_t mutex;
pthread_cond_t pizzaAvailable;

void* studentThread(void* arg)
{
    while (true)
    {
        pthread_mutex_lock(&mutex);
        while (pizzaCount == 0)
        {
            cout << "Waiting for pizza" << endl;
            pthread_cond_wait(&pizzaAvailable, &mutex);
        }
        pizzaCount--;
        cout << "Eating pizza while studying" << endl;
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
    pthread_exit(NULL);
}

void* pizzaDeliveryThread(void* arg)
{
    while (true)
    {
        pthread_mutex_lock(&mutex);
        if(pizzaCount == 0)
        {
            pizzaCount = numberOfPieces;
            cout << "Pizza delivered." << endl;
            checkpieces += numberOfPieces;
            pthread_cond_broadcast(&pizzaAvailable);
            pizzaCount--;
            if(checkpieces >= 25)
                {
                    cout << "Time completed for all students. " << endl;
                    cout <<"Program exiting"<<endl;
                    exit(0);
                }
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    cout << "Enter number of students: ";
    cin >> numberOfStudents;
    cout << "Enter number of pieces in each pizza: ";
    cin >> numberOfPieces;

    pthread_t tid[numberOfStudents];
    pthread_t deliveryThread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&pizzaAvailable, NULL);

    pthread_create(&deliveryThread, NULL, pizzaDeliveryThread, NULL);
    for (int i = 0; i < numberOfStudents; i++)
    {
        pthread_create(&tid[i], NULL, studentThread, NULL);
    }

    pthread_exit(NULL);
}