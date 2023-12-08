#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;

int main() {
    int parentToChildPipe[2];  
    int childToParentPipe[2];  

    if (pipe(parentToChildPipe) == -1 || pipe(childToParentPipe) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        close(parentToChildPipe[1]);  //Write Closed
        close(childToParentPipe[0]);  //Read Closed

        while (true) {
            char messageFromParent[256];
            ssize_t bytesRead = read(parentToChildPipe[0], messageFromParent, sizeof(messageFromParent));

            messageFromParent[bytesRead] = '\0';

            if (strcmp(messageFromParent, "exit") == 0) {
                break;  
            }

            cout << "C received: " << messageFromParent << endl;

            cout << "C response: ";
            char response[256];
            cin.getline(response, sizeof(response));

            write(childToParentPipe[1], response, strlen(response));
        }

        close(parentToChildPipe[0]);
        close(childToParentPipe[1]);
    } else {
        Parent process (P)
        close(parentToChildPipe[0]);  
        close(childToParentPipe[1]);  

        while (true) {
            cout << "P message: ";
            char messageToChild[256];
            cin.getline(messageToChild, sizeof(messageToChild));

            write(parentToChildPipe[1], messageToChild, strlen(messageToChild));

            if (strcmp(messageToChild, "exit") == 0) {
                break;  
            }

            char responseFromChild[256];
            ssize_t bytesRead = read(childToParentPipe[0], responseFromChild, sizeof(responseFromChild));

            responseFromChild[bytesRead] = '\0'; 

            cout << "P received: " << responseFromChild << endl;
        }

        close(parentToChildPipe[1]);
        close(childToParentPipe[0]);

        wait(nullptr);
    }

    return 0;
}
