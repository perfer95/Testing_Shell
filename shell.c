#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h> /*<strtok> */


int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *token;
	char **arr_token;
	pid_t child_pid;
	int i = 0, status;

	while (1)
	{
		write(1, "$ ", 2);
		getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, "\t\n");
		arr_token = malloc(sizeof(char *) * 1024);

		while (token != NULL)
		{
			arr_token[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}

		arr_token[i] = NULL;
		child_pid = fork(); /*Print error -1*/
		if (child_pid == -1)
		{
			perror("Error eith fork");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (execve(arr_token[0], arr_token, NULL) == -1)
			{
				perror("Error with execve");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(arr_token);
	}
	return (0);
}
