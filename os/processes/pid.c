/*
Write a C-program that prints its own PID on the screen.
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    printf("%d", getpid()); // process id of the current process
}