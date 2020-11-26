#include "header.h"

/**
 * check_path - Function that chekc if path its pk.
 * @route: Pointer to path variable.
 * Return: Pointer to new modify path or older path.
 */
char *check_path(char *route)
{
	unsigned int i, j = 0;
	char *newroute = NULL;

	if (route[5] == ':')
	{
		newroute = malloc(sizeof(char) * _strlen(route) + 2);
		for (i = 0; route[i]; j++, i++)
		{
			newroute[j] = route[i];
			if (route[i + 1] == ':' && i == 4)
			{
				newroute[i + 1] = '.';
				j++;
			}
		}
		newroute[j] = '\0';
		return (newroute);
	}
	return (route);

}
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
	char *_newenviron = NULL;
	char *conc = NULL;
	char **_path = NULL;
	unsigned int dir = 1;
	unsigned int flag = 0;

	_environ = _getenv(P);
	if (_environ && _strlen(_environ) > 5)
	{
		_newenviron = check_path(_environ);
		if (_strcmp(_newenviron, _environ) != 0)
		{
			_environ = _newenviron;
			flag = 1;
		}
		_path = get_pointers_array(_environ, limit);
		while (_path[dir])
		{
			conc = _pathcat(_path[dir], arr[0]);
			if (stat(conc, &buf) == 0)
			{
				arr[0] = conc;
				if (flag == 1)
					free(_environ);
				status_exec(arr);
			}
			free(conc);
			dir++;
		}
		free(_path);
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
	unsigned int i = 0, n = 0;
	char *retvalue = NULL;

	if (environ)
	{
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
	int status = 1;
	char **ptrret = NULL;
	char *line = NULL;

	/* Search in built_in commands*/
	if (argument[0])
	{
		status = get_built_func(argument)(argument);
		if (status != 2)
		{
			free(argument);
			return (status);
		}
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
			line = argument[0];
			free(line);
			free(argument);
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
		else
			wait(0);
	}
	free(argument);
	return (status);
}
