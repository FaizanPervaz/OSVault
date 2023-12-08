#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int TT_CARS = 4;
const int TT_BUSES = 1;

queue<int> car_d;
queue<int> bus_d;

int cars_count = 0;
int bus_count = 0;
int car_wait = 0;
int bus_wait = 0;

pthread_mutex_t bridge;
pthread_cond_t c_bridge;

void ArriveAtBridge(int direction, int vehicle_type) {
    pthread_mutex_lock(&bridge);
    if (vehicle_type == 0) { 
        while (bus_count > 0 || cars_count >= TT_CARS || 
               (bus_wait > 0 && cars_count >= TT_CARS - 2)) {
            car_d.push(direction);
            car_wait++;
            cout << "A car waiting to cross the bridge in direction " << direction << ". Total cars waiting: " << car_wait << endl;
            pthread_cond_wait(&c_bridge, &bridge);
        }
        cars_count++;
        cout << "The bridge is being crossed by a car in direction " << direction << ". Total cars on the bridge: " << cars_count << endl;

    } else { 
        while ((cars_count >= TT_CARS - 2) || (bus_count >= TT_BUSES) || 
               (bus_count == 1 && !bus_d.empty() && direction != bus_d.front())) {
            bus_d.push(direction);
            bus_wait++;
            cout << "A bus is waiting to cross the bridge in direction " << direction << ". Total buses waiting: " << bus_wait << endl;
            pthread_cond_wait(&c_bridge, &bridge);
        }
        bus_count++;
        cout << "The bridge is being crossed by a bus in direction " << direction << ". Total buses on the bridge: " << bus_count << endl;
    }
    pthread_mutex_unlock(&bridge);
}

void ExitTheBridge() {
    pthread_mutex_lock(&bridge);
    if (bus_count > 0) {
        cout<< "The bridge has been exited by a bus. Total buses on the bridge: " << bus_count << endl;
        bus_count--;
    } else if (cars_count > 0) {
        cout << "The bridge has been exited by a car. Total cars on the bridge: " << cars_count << endl;
        cars_count--;
    }

    while (!bus_d.empty() && bus_count == 0 && cars_count <= TT_CARS - 2) {
        int next_direction = bus_d.front();
        bus_d.pop();
        bus_wait--;
        ArriveAtBridge(next_direction, 1);
    }
    while (!car_d.empty() && cars_count < TT_CARS && bus_count == 0) {
        int next_direction = car_d.front();
        car_d.pop();
        car_wait--;
        ArriveAtBridge(next_direction, 0);
    }
    pthread_cond_broadcast(&c_bridge);
    pthread_mutex_unlock(&bridge);
}


void *thread_function(void *arg) {
    int direction = rand() % 2;
    int vehicle_type = rand() % 2;
    ArriveAtBridge(direction, vehicle_type);
    usleep(2000000);
    ExitTheBridge();
    pthread_exit(NULL);
}

int main() 
{
    pthread_mutex_init(&bridge, NULL);
    pthread_cond_init(&c_bridge, NULL);

    pthread_t tid[10];
    for (int i = 0; i < 10; i++) {
        int *vehicle_id = new int(i+1); 
        pthread_create(&tid[i], NULL, thread_function, (void *) vehicle_id);
        usleep(1000000);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&bridge);
    pthread_cond_destroy(&c_bridge);

    return 0;
}

