#include "header.h"

char *exit_func(char *pr)
{
	printf("Funcion %s\n", pr);
	return (pr);
}
char *cd_func(char *pr)
{
	printf("Funcion %s\n", pr);
	return (pr);
}

char *wrong_built(__attribute__((unused))char *pr)
{
	return('\0');
}
/***funcion*******/
char *(*get_built_func(char *gu))(char *arg)
{
	built builts[] = {
		{"exit", exit_func},
		{"cd", cd_func},
		{'\0', '\0'},
		{"wrong", wrong_built}
	};
	int i = 0;
	while( builts[i].indic != '\0')
	{
		if ( strcmp(gu, builts[i].indic) == 0)
		{
			return(builts[i].function);
		}
		i++;
	}
	return (builts[i + 1].function);
}
