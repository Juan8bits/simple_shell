#include "header.h"

/**
 * status_exec -
 */

void status_exec(char **argum)
{
	struct stat buf;

	if (stat(argum[0], &buf) == 0)
	{
		if (execve(argum[0], argum, environ) == -1)
		{
			perror("./shell");
			_exit(0);
		}
	}
	return;
}

/**
 * new_process - This function
 * @argument: Double pointer to pointers array.
 * Return: int number.
 */

int new_process(char **argument)
{
	pid_t pid;
	char *P = "PATH";
	char *limit =  ":\n";
	char *_environ = NULL;
	char **_path = NULL;
	int prueba = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("./shell");
		return (-1);
	}
	if (pid == 0)
	{
		status_exec(argument);

		_environ = _getenv(P);

		_path = get_pointers_array(_environ, limit);

		while (_path[prueba])
		{
			printf("[%d]%s\n", prueba, _path[prueba]);
			prueba++;
		}
		prueba = 0;
		/*
		while (_path[i])
		{
		concat_route(_path[i], argument[0])
		}*/
		perror("./shell");
		_exit(0);

	}
	else
	{
		wait(0);
		free(argument);
	}
	return (0);
}
