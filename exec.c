#include "header.h"
/**
 * new_process - This function
 *
 */

/*extern char **environ;*/

int new_process(char **argument)
{
	pid_t pid;
	struct stat buf;
	char *set[] = {"","","./", NULL};
	pid = fork();

	if (pid == 0)
	{
		if (stat(argument[0], &buf) == 0)
		{
			printf("\nENTREEEEEEEEEEEEE\n");
			if (execve(argument[0], argument, environ) == -1)
				printf("INVALID PATH\n");
		}
		else
		{
			printf("THIS PATH IS FAIL\n");
		}
	}
	else if (pid > 0)
	{
		wait(0);
	}
	else if (pid < 0)
	{
		perror("ERROR");
		return (-1);
	}
	return (0);
}
