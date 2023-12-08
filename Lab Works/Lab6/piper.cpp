#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

int main()
{
    int fd = open("pipe1", O_RDONLY); 
    int fd1 = open("pipe2", O_WRONLY);

    while (1)
    {
        char buf[10];
        read(fd, buf, sizeof(buf));
        cout << "Read: " << buf << endl;
        if (strcmp(buf, "exit") == 0)
            break;

        char tuf[10];
        cout << "Enter to Write: ";
        cin >> tuf;
        write(fd1, tuf, strlen(tuf) + 1);
    }
    close(fd);
    close(fd1);
}
