#include "header.h"
/**
 * _getenv - Function that searches the first characters of the environment
 * for a string.
 * @name: Name of enviroment variale.
 * Return: Pointer to environ variable finded.
 */
char *_getenv(char *name)
{
	int size, i = 0;
	unsigned int n = 0;
	char *retvalue = NULL;

	for (size = 0; name[size] != '\0'; size++)
		;
	while (environ[i])
	{
		n = _strcmp(name, environ[i]);
		if (n == 0)
		{
			retvalue = environ[i];
			break;
		}
		i++;
	}
	return (retvalue);
}
/**
 * status_exec - Function that asks for the existence of
 * a file and if it exists executes it.
 * @argum: Pointer to pointers array.
 */

void status_exec(char **argum)
{
	struct stat buf;

	if (stat(argum[0], &buf) == 0)
	{
		if (execve(argum[0], argum, environ) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
	}
}

/**
 * new_process - Function that create a new child process.
 * @argument: Double pointer to pointers array.
 * Return: int number.
 */

int new_process(char **argument)
{
	struct stat buf;
	pid_t pid;
	char *P = "PATH", *limit =  ":=\n", *_environ = NULL, *conc = NULL;
	char **_path = NULL;
	int dir = 1;

	pid = fork();
	if (pid < 0)
		perror("./shell");
	else if (pid == 0)
	{	status_exec(argument);/*When the route is given in argument[0]*/
/*If child process don´t finish before, it´s going*/
/*to search if the argument[0] could be there in $PATH.*/
		_environ = _getenv(P);
		_path = get_pointers_array(_environ, limit);
		while (_path[dir])
		{	conc = _pathcat(_path[dir], argument[0]);
			if (stat(conc, &buf) == 0)
			{	argument[0] = conc;
				status_exec(argument);
			}
			free(conc);
			dir++;
		}
/*If the argument[0] doesn´t exist, it´s going*/
/*to search in buit-in functions*/
		perror("./shell");
		_exit(EXIT_FAILURE);
	}
	else
	{	wait(0);
		free(argument);
	}
	return (1);
}
