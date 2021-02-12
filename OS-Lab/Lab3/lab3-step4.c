//Alex Varon
//Lab 3 - Step 4
//10/7/2020
//This program implements the shell command: cat /etc/passwd | grep root
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//main
int main() {
    int fds[2];
    pipe(fds);
    //first child duplicates downstream into stdin
    if (fork() == 0) {
        dup2(fds[0], 0);//reading end of pipe
        close(fds[1]);//closes writing end of pipe
        execlp("grep", "grep", "root", 0);
    //second child duplicates upstream into stdout
    } else if (fork() == 0) {
        dup2(fds[1], 1);//writing end of pipe
        close(fds[0]);//closes reading end
        execlp("cat", "cat", "/etc/passwd", 0);
    } else {  //parent closes both ends and wait for children
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
        return 0;
}

