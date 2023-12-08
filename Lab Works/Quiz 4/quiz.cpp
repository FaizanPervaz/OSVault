#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int no_of_students, no_of_pieces, pizza_count = 0;
int check_pieces = 0;

pthread_mutex_t mutex;
pthread_cond_t pizza_avail;

void* eat_pizza_thread(void* arg) 
{
    int pieces_eaten = 0;
    while (true) { 
        pthread_mutex_lock(&mutex);
        while (pizza_count == 0) 
        {
            cout << "Waiting for pizza" << endl;
            pthread_cond_wait(&pizza_avail, &mutex);
        }
        pizza_count--;
        pieces_eaten++;
        cout << "Eating pizza while studying" << endl;
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
    pthread_exit(NULL);
}

void* del_pizza_thread(void* arg) 
{
    while (true) 
    {
        pthread_mutex_lock(&mutex);
        if (pizza_count == 0) 
        {
            pizza_count = no_of_pieces;
            cout << "Pizza delivered." << endl;
            check_pieces += no_of_pieces;
            pthread_cond_broadcast(&pizza_avail);
            //har student 5 slices khaye ga tou total 25 pr check krna hai
            if (check_pieces >= no_of_students * 5) 
            {  
                cout << "Time completed for all students." << endl;
                cout << "Program exiting" << endl;
                exit(0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    cout << "Enter number of students: ";
    cin >> no_of_students;
    cout << "Enter number of pieces in each pizza: ";
    cin >> no_of_pieces;

    pthread_t tid[no_of_students];
    pthread_t deliveryThread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&pizza_avail, NULL);

    pthread_create(&deliveryThread, NULL, del_pizza_thread, NULL);

    for (int i = 0; i < no_of_students; i++) {
        pthread_create(&tid[i], NULL, eat_pizza_thread, NULL);
    }

    pthread_join(deliveryThread, NULL);

    for (int i = 0; i < no_of_students; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}
