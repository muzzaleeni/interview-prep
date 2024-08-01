/*
Write a C-program that spawns another process using fork(). 
Both parent and child processes announce their existence (through a printf) and their PIDs.
*/

#include <unistd.h>
#include <stdio.h>

int main() {   
    pid_t cp = fork();
    if (cp == 0) { // child process
        printf("Child with PID %d is alive\n", getpid());
    }
    else if (cp == -1) { // failed forking
        printf("Faield forkign");
    }
    else { // parent process
        printf("Parent with PID %d is alive\n", getpid());
    }
}