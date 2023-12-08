#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t water_tank; 
sem_t personSem;

int getting_water = 0;

void* personThread(void* args) 
{
  int* person = (int*)args;

  while (true) {
    sem_wait(&personSem);

    if (getting_water >= 5) 
    {
        getting_water -= 5;
        cout<<"Water : "<<getting_water<<"L."<<"\n"<< "Person :"<<*person<<" took 5L of water." <<endl;
    } else 
    {
        cout<<"Water : "<<getting_water<<"L."<<"\n"<< "Person :"<<*person<<" waiting." <<endl;
    }
    cout<<endl;
    sem_post(&personSem);

    int time = rand() % 3 + 1;
    usleep(time*1000000);
  }

  return NULL;
}

void* filterThread(void* args) {

  while (true) {
    sem_wait(&water_tank);

    if (getting_water < 10) 
    {
        getting_water += 10;
        cout<<"Filter : "<<getting_water<<"L added."<<"\n"<< "Total Water : "<<getting_water<<" L." <<endl;
    }
    cout<<endl;
    
    sem_post(&water_tank);

    usleep(1000000);
  }

  return NULL;
}

int main() {
    pthread_t t_filter;
    pthread_t t_person[5];
    int person_tid[5];

    sem_init(&water_tank, 0, 1);
    sem_init(&personSem, 0, 3);

    pthread_create(&t_filter, NULL, filterThread, NULL);

    for (int i = 0; i < 5; i++) {
        person_tid[i] = i++;
        pthread_create(&t_person[i], NULL, personThread, &person_tid[i]);
    }

    pthread_join(t_filter, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_join(t_person[i], NULL);
    }

    sem_destroy(&water_tank);
    sem_destroy(&personSem);

    pthread_exit(NULL);
    return 0;
}