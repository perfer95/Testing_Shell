#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h> /*<strtok> */


void check_command(char *command)
{
    if (access(command, F_OK) == 0)
    {
        printf("%s: FOUND THE FILE\n", command);
    }
    else
    {
	printf("%s: NOT FOUND THE FILE\n", command);
    }
}

int main(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    char *token;

    while (1)
    {
        write(1, "$ ", 2);
        getline(&buffer, &buffer_size, stdin);
        token = strtok(buffer, " \t\n");

        if (strcmp(token, "which") == 0)
        {
            token = strtok(NULL, " \t\n");
            while (token)
            {
                check_command(token);
                token = strtok(NULL, " \t\n");
            }
        }
        else
        {
            write(1, "COMMAN NOT FOUND\n", 18);
        }
    }
    return (0);
}
