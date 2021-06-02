#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

    char* cmd[4][4];
    cmd[0][0] = "cat"; cmd[0][1] = "sos"; cmd[0][2] =  NULL;
    cmd[1][0] = "grep"; cmd[1][1] = "BSD"; cmd[1][2] = NULL;
    cmd[2][0] = "sort"; cmd[2][1] = "-r"; cmd[2][2] =  NULL};
    cmd[3][0] = "head"; cmd[3][1] = "-n"; 
      cmd[3][2] = "1"; cmd[3][3] = NULL;

    int fd[2];

    pipe(fd);

    int pid = fork();

    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execvp(cmd[0][0], cmd[0]);
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execvp(cmd[1][0], cmd[1]);
    }

}