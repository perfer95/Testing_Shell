#include <stdio.h>
#include <unistd.h>

/**
 * main - print PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid; // could be decimal or llu

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
