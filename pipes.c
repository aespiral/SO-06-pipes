#include <unistd.h>
#include <stdio.h>

int main () {

    int fd[2];

    pipe(fd);

    int pid = fork();

    if (pid == 0) {
        close(fd[0]);
        char* msg = "Hello, friend, it's a shame!";
        write(fd[1], msg, 16);
        while(1);

    } else {
        close(fd[1]);
        char buf[256];
        int n = read(fd[0], buf, 256);
        buf[n] = '\0';
        puts(buf);

    }

}