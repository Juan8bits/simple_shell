#include "header.h"

/**
 * env_func - Function that print the environment variables.
 * @pr: Unused variable.
 * Return: Always 1.
 */
int env_func(__attribute__((unused))char **pr)
{
	unsigned int j;

	for (j = 0; environ[j]; j++)
		printf("%s\n", environ[j]);
	return (1);
}
/**
 * exit_func - Function that imitates the buit-in exit of shell.
 * @pr: Unused variable.
 * Return: Always 0.
 */
int exit_func(__attribute__((unused))char **pr)
{
	return (0);
}

/**
 * cd_func - Function that imitates the buit-in cd of shell.
 * @pr: Arguments given to compare with the buit-in.
 * Return: Always 1.
 */
int cd_func(char **pr)
{
	char *home = NULL;
	char *_home = "HOME";

	if (pr[1] == NULL)
	{
		home = _getenv(_home);
		home += 5;
		if (chdir(home) != 0)
			perror("./shell:");
	}
	else
	{
		if (chdir(pr[1]) != 0)
			perror("./shell:");
	}
	return (1);
}

/**
 * wrong_built - Function called when the passed argument is not
 * found in the built_in command structure.
 * @pr: Unused attribute.
 * Return: Always 2.
 */
int wrong_built(__attribute__((unused))char **pr)
{
	return (2);
}
/**
 * get_built_func - Function to redirec a pointer to function
 * depending to argument given.
 * @args: Arguments given to compare with the buit-in.
 * Return: pr on fail, end of the process on succesful.
 */
int (*get_built_func(char **args))(char **)
{
	built builts[] = {
		{"exit", exit_func},
		{"cd", cd_func},
		{"env", env_func},
		{'\0', '\0'},
		{"wrong", wrong_built}
	};
	short int i = 0;

	while (builts[i].indic != '\0')
	{
		if (_strcmp(args[0], builts[i].indic) == 0)
		{
			return (builts[i].function);
		}
		i++;
	}
	return (builts[i + 1].function);
}
