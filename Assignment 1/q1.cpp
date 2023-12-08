//20I-0565 Faizan
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL)); 

    int random_no = (rand() % 98) + 1;
    int mul_roll = random_no * 5;
    int divide_no = 565 / mul_roll;
    int n = divide_no % 25;

    if (n < 10)
    {
        n = n + 10;
    }

    cout << "N = "<<n<< endl;

    int arr1[n][n];
    int arr2[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1[i][j] = (rand() % 98) + 1;
            arr2[i][j] = arr1[i][j];
        }
    }

    ofstream files[n];

    for (int i = 0; i < n; i++)
    {
        string filename = "file" + to_string(i) + ".txt";
        files[i].open(filename.c_str());
    }

    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();
        
        if (pid == 0)
        {
            cout << "Child process " << i << " havng pid " << getpid() <<endl;

            files[i] << "Process ID: " << getpid() << endl;
            for (int row = i; row < i + 1; row++) 
            {
                for (int j = 0; j < n; j++)
                {
                    int result = 0;
                    for (int k = 0; k < n; k++)
                    {
                        result += arr1[row][k] * arr2[k][j];
                    }
                    files[i] << result << " ";
                }
                files[i] << endl;
            }

            files[i].close(); 

            exit(0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }

    cout<<"\nResultant Matrix : "<<endl;
    for (int i = 0; i < n; i++) {
        string filename = "file" + to_string(i) + ".txt";
        ifstream file(filename.c_str());

        if (file.is_open()) 
        {
            string line;
            getline(file, line);
            while (getline(file, line)) 
            {
                cout << line << endl;
            }
            file.close();
        } 
    }

    return 0;
}
