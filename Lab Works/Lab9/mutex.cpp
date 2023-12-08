#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int account_balance = 100;

pthread_mutex_t money_deposit_lock;
void *money_deposit(void *) 
{
    pthread_mutex_lock(&money_deposit_lock);

    for (int i = 0; i < 10; i++) 
    {
        cout << "At time " << i << " the balance before depositing thread " << account_balance << endl;
        account_balance += 11; 
        sleep(10);
        cout << "At time " << i << " the balance after depositing thread " << account_balance << endl;

        sleep(10);
    }

    pthread_mutex_unlock(&money_deposit_lock);
    pthread_exit(NULL);
}

pthread_mutex_t money_withdrawl_lock;
void *money_withdrawl(void *) 
{
    pthread_mutex_lock(&money_withdrawl_lock);
    for (int i = 0; i < 10; i++) 
    {
        if (account_balance < 10) 
        {
            cout << "At time " << i << " Thread Widrawal is waiting for funds." << endl;
        } 
        else
        {
            cout << "At time " << i << " the balance for withdrawal thread" << account_balance << endl;
            account_balance -= 10;
            sleep(1);
            cout << "At time " << i << " the balance after withdrawal thread " << account_balance << endl;
        }

        sleep(1);
    }

    pthread_mutex_unlock(&money_withdrawl_lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t withdraw_thread1;
    pthread_t withdraw_thread2;
    pthread_t deposit_thread1;
    pthread_t deposit_thread2;

    pthread_create(&withdraw_thread1, NULL, money_withdrawl, NULL);
    pthread_create(&withdraw_thread2, NULL, money_withdrawl, NULL);
    pthread_create(&deposit_thread1, NULL, money_deposit, NULL);
    pthread_create(&deposit_thread2, NULL, money_deposit, NULL);

    pthread_join(withdraw_thread1, NULL);
    pthread_join(withdraw_thread2, NULL);
    pthread_join(deposit_thread1, NULL);
    pthread_join(deposit_thread2, NULL);

    pthread_mutex_destroy(&money_withdrawl_lock);
    pthread_mutex_destroy(&money_deposit_lock);

    return 0;
}
