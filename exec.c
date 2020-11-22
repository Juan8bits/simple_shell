#include "header.h"
/**
 * new_process - This function
 *
 */

int new_process(char **argument)
{
	pid_t pid;
	struct stat buf;
	char *set[] = {" ", NULL};
	pid = fork();

	
	if (argument && set[0])
	{
		if (pid < 0)
		{
			perror("ERROR");
			return (-1);
		}
		if (pid == 0)
		{
			if (stat(argument[0], &buf) == 0)
			{
				printf("\nENTREEEEEEEEEEEEE\n");
				if (execve(argument[0], argument, environ) == -1)
				{
					perror("./shell: ");
					_exit(0);
				}				
			}
			else
			{
				printf("THIS PATH IS FAIL\n");
				exit(0);
			}
		}
		else
		{
			wait(0);
		}
		
	}
	return (0);
}
