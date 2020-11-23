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
        unsigned int n;
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
 * @argume: Pointer to pointers array.
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
 * new_process - Function that create a new child process.
 * @argument: Double pointer to pointers array.
 * Return: int number.
 */

int new_process(char **argument)
{
	pid_t pid;
	char *P = "PATH";
	char *limit =  ":=\n";
	char *_environ = NULL, *conc = NULL;
	char **_path = NULL;
	short int dir = 1;

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
/*while (_path[prueba])
{
printf("[%d]%s\n", prueba, _path[prueba]);
prueba++;
}
prueba = 0;*/	while (_path[dir])
		{
			conc = concat_route(_path[dir], argument[0]);
			argument[0] = conc;
			status_exec(argument);
			dir++;
		}
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
