#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

int main()
{
    mkfifo("pipe1", 0666);
    mkfifo("pipe2", 0666);  

    int fd = open("pipe1", O_WRONLY);
    int fd1 = open("pipe2", O_RDONLY); 
    while (1)
    {
        char buf[10];
        cout << "Enter to Write: ";
        cin >> buf;
        write(fd, buf, strlen(buf) + 1);

        char tuf[10];
        read(fd1, tuf, sizeof(tuf));
        cout << "Read: " << tuf << endl;
        if (strcmp(tuf, "exit") == 0)
            break;
    }
    close(fd);
    close(fd1);
}
