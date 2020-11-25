#include "header.h"

/**
 * search_in_path - Function that find the command (arr[0]) in PATH
 * @arr: Pointer to pointers array that contains the commands given.
 * Return: Double pointer.
 */
char **search_in_path(char **arr)
{
	struct stat buf;
	char *P = "PATH";
	char *limit =  ":=\n";
	char *_environ = NULL;
	char *conc = NULL;
	char **_path = NULL;
	unsigned int dir = 1;

	_environ = _getenv(P);
	_path = get_pointers_array(_environ, limit);
	while (_path[dir])
	{
		conc = _pathcat(_path[dir], arr[0]);
		if (stat(conc, &buf) == 0)
		{
			arr[0] = conc;
			status_exec(arr);
		}
		free(conc);
		dir++;
	}
	return (NULL);
}
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
	pid_t pid;
	int status = 0;
	char **ptrret = NULL;

	/* Search in built_in commands*/
	status = get_built_func(argument)(argument);
	if (status == 2)
	{
		pid = fork();
		if (pid < 0)
			perror("./shell");
		else if (pid == 0)
		{
			/* Search the argument in PATH*/
			ptrret = search_in_path(argument);
			if (!ptrret)
			{
				/*if the arugment doesn´t exist in PATH,*/
				/*search in current directory*/
				status_exec(argument);
			}
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(0);
			/*free(argument);*/
		}
	}
	free(argument);
	return (status);
}
