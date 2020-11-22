#include "header.h"

/**
 * which_conc - Function that search an a given command in $PATH and concatenate
 *  it with the directory.
 * @route: Pointer to string.
 * Return: 1 on succesful,
 */
size_t which_conc(char *route)
{
	(void) route;
	return(0);
}

/**
 * new_process - This function
 * @argument: Double pointer to pointers array.
 * Return: int number.
 */

int new_process(char **argument)
{
	pid_t pid;
	struct stat buf;
	/*char *set[] = {" ", NULL};*/
	pid = fork();

	if (pid < 0)
	{
		perror("./shell");
		return (-1);
	}
	if (pid == 0)
	{
		if (stat(argument[0], &buf) == 0)
		{
			if (execve(argument[0], argument, environ) == -1)
			{
				perror("./shell");
				_exit(0);
			}
		}
		else
		{
			if (which_conc(argument[0]) == 1)
			{
				if (execve(argument[0], argument, environ) == -1)
				{
					perror("./shell");
					_exit(0);
				}
			}
			perror("./shell");
			_exit(0);
		}
	}
	else
	{
		wait(0);
		free(argument);
	}
	return (0);
}
