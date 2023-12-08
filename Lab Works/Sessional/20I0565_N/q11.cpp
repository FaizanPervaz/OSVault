#include <iostream>
#include <ctime>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstring>
using namespace std;

int main() {
    int n = 0;
    srand(time(NULL));
    int guessno = (rand() % 100) + 1;
    cout<<guessno<<endl;
    
    int A[2];
    int B[2];

    pipe(A);
    pipe(B);

    pid_t p = fork();

    if (p == 0) {
        close(A[1]);
        close(B[0]);
        
        while (n < 10) {
            char guess[2];
            read(A[0], guess, sizeof(guess));

            int guessA = atoi(guess);

            if (guessA == guessno) {
                cout << "Player A wins with guess: " << guessA << endl;
                break;
            } 

            n++;

            char guess1[2];
            cout << "Player A Enter Number: ";
            cin >> guess1;
            write(B[1], guess1, strlen(guess1) + 1);
        }
    } else {
        close(A[0]);
        close(B[1]);
        
        while (n < 10) {
            char guess1[2];
            cout << "Player B Enter Number: ";
            cin >> guess1;
            write(A[1], guess1, strlen(guess1) + 1);

            char guess[2];
            read(B[0], guess, sizeof(guess));

            int guessB = atoi(guess);

            if (guessB == guessno) {
                cout << "Player B wins with guess: " << guessB << endl;
                break;
            } 

            n++;
        }
    }
    return 0;
}
