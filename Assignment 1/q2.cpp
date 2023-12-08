//20I-0565 Faizan

#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstring>

using namespace std;

int main() {
    int exitCondition = 1; 
    
    while (exitCondition) {
        pid_t p1, p2;
        p1 = fork();

        if (p1 == 0) {
            int var1 = 0;
            cout << "Child's Process ID : " << getpid() << endl;
            cout << "Enter 1 to write in shared memory : \nEnter 2 to read from shared memory : " << endl;
            cin >> var1;

            if (var1 == 1) {
                execlp("./s", "s.exe", NULL);
            } else if (var1 == 2) {
                execlp("./r", "r.exe", NULL);
            } else {
                cout << "Invalid Input" << endl;
            }
        } else {
            wait(NULL);
            p2 = fork();
            if (p2 == 0) {
                int var2 = 0;
                cout << "Parent's Process ID : " << getpid() << endl;
                cout << "Enter 1 to write in shared memory : \nEnter 2 to read from shared memory : " << endl;
                cin >> var2;

                if (var2 == 1) {
                    execlp("./s", "s.exe", NULL);
                } else if (var2 == 2) {
                    execlp("./r", "r.exe", NULL);
                } else {
                    cout << "Invalid Input" << endl;
                }
            } else {
                wait(NULL);

                cout << "Wish to Continue? (1/0): ";
                cin >> exitCondition;
            }
        }
    }
}

			/*SYNCHRONIZATION ISSUES*/
/*There are several issues that arise incase of shared memory. Some of them are as follow:

1: Race Condition: This problem arises when multiple processes try to access shared memory at the same time because order of the access can not be determined. The solution to this problem is to use locks or semaphores.

2: Deadlocks: This problem arises when one process puts lock on the resources and another process waits for that lock to be released. The solution to this problem is to use a locking mechanism which releases the resources in a timely manner.

3: Inconsistency: This problem arises when more than one process try to access and modify the same memory location at the same time. In that case data at that particular memory location does not remain consistent. The solution to this problem is to use atomic operations. It means that only one process can access a particular memory location at a time.

4: Cache Coherency: Every process has its own cache memory. When one process changes data in shared memory which the cache of another processs also holds. Then the data in the second process's cache stand invalid. As a solution to this problem protocols such as MESI should be used.*/

