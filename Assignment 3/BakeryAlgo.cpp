#include <iostream>
#include <pthread.h>
#include <atomic>
using namespace std;

class BakeryLock {
private:
    int* ticket_no;
    atomic<bool>* flag;
    int num_threads;

public:
    BakeryLock(){}
    BakeryLock(int num_threads) :  num_threads(num_threads){
        ticket_no = new int[num_threads];
        flag = new atomic<bool>[num_threads];

        for (int i = 0; i < num_threads; i++) 
        {
            ticket_no[i] = 0;
            flag[i] = false;
        }
    }

    void lock(int thread_id) {
        flag[thread_id].store(true, memory_order_seq_cst);
        int ticket_max = 0;
        for (int i = 0; i < num_threads; ++i) 
        {
            if (flag[i].load(memory_order_seq_cst) && (ticket_no[i] > ticket_max)) 
            {
                ticket_max = ticket_no[i];
            }
        }
        ticket_no[thread_id] = ticket_max + 1;
        flag[thread_id].store(false, memory_order_seq_cst);

        //we can handle the loop instead of busy waiting by using compare exchange weak
        for (int i = 0; i < num_threads; ++i) 
        {
            if (i != thread_id) {
                while (flag[i].load(memory_order_seq_cst)) 
                {

                }
                while ((ticket_no[i] != 0) && ((ticket_no[i] < ticket_no[thread_id]) || (ticket_no[i] == ticket_no[thread_id] && i < thread_id))) 
                {
                    
                }
            }
        }
    }

    void unlock(int thread_id) 
    {
        ticket_no[thread_id] = 0;
    }
};

void* lock_unlock(void* temp) 
{
    BakeryLock obj(5);
    int tid = *(int*)temp;
    obj.lock(tid);
    cout << "In Critical Section Thread " << tid << "\n";
    obj.unlock(tid);
    cout << "Exited the Critical Section Thread " << tid << "\n";
    
    return NULL;
}

int main() {
    pthread_t threads[3];
    int tid[] = {0, 1, 2};
    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, lock_unlock, (void*)&tid[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_exit(NULL);
    return 0;

}
