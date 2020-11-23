#include "header.h"

/**
 * _pathcat - jhu
 * @argument: h
 * @route:hgh
 * Return: Value
 */

int main(void)
{
         char *s1 = "Hello ";
         char *s2 = "World!\n";
         char *p;

         printf("%s\n", s1);
         printf("%s", s2);

         p = _pathcat(s1, s2);
         printf("%s\n", p);

         return (0);
}

char *_pathcat(char *argument, char *route)
{
	char *conc = NULL;
	unsigned int lengA;
	unsigned int lengR;
	
	lengA = _strlen(argument);
	lengR = _strlen(route);

	conc = malloc(lengA + lengR);
	
	if (conc == '\0')
		return (NULL);

	conc = _strcpy(conc, route);
	conc = _strcat(conc, argument);

	return (conc);
}
