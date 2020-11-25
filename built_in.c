#include "header.h"

/**
 * exit_func - Function that imitates the buit-in exit of shell.
 * @pr: Argument given to compare with the buit-in.
 * Return: pr on fail, end of the process on succesful.
 */
char *exit_func(char *pr)
{
	printf("Funcion %s\n", pr);
	return (pr);
}

/**
 * cd_func - Function that imitates the buit-in cd of shell.
 * @pr: Argument given to compare with the buit-in.
 * Return: pr on fail, end of the process on succesful.
 */
char *cd_func(char *pr)
{
	printf("Funcion %s\n", pr);
	return (pr);
}

/**
 * wrong_built - Function that imitates the buit-in exit of shell.
 * @pr: Unused attribute.
 * Return: Always NULL.
 */
char *wrong_built(__attribute__((unused))char *pr)
{
	return ('\0');
}
/**
 * get_built_func - Function to redirec a pointer to function
 * depending to argument given.
 * @pr: Argument given to compare with the buit-in.
 * Return: pr on fail, end of the process on succesful.
 */
char *(*get_built_func(char *gu))(char *)
{
	built builts[] = {
		{"exit", exit_func},
		{"cd", cd_func},
		{'\0', '\0'},
		{"wrong", wrong_built}
	};
	int i = 0;

	while (builts[i].indic != '\0')
	{
		if (_strcmp(gu, builts[i].indic) == 0)
		{
			return (builts[i].function);
		}
		i++;
	}
	return (builts[i + 1].function);
}
