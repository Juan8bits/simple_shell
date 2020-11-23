#include "header.h"

/**
 * _strlen - Return the length of a string
 * @s: string given.
 * Return: z
 */

int _strlen(char *s)
{
	int z = 0;

	while (s[z] != '\0')
		z++;
	return (z);
}
/**
 * _strcmp - Functiont that compare two strings
 * @s1: String to compare 1.
 * @s2: String to compare 2.
 * Return: if Return value < 0 then it indicates str1 is less than str2.
 *	if Return value > 0 then it indicates str2 is less than str1.
 *	if Return value = 0 then it indicates str1 is equal to str2.
*/

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0, rest = 0;

	while (s1[i] != 0 && s2[i] != 0)
	{
		rest = s1[i] - s2[i];
		if (rest != 0)
			break;
		i++;
	}
	return (rest);
}
/**
 * _strcat - Function that concatenates two strings
 * @dest: string concatenates
 * @src: string source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	unsigned int i, j;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copy strings
 * @dest: destiny string
 * @src: source string
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	unsigned int leng = 0;

	while (src[leng] != '\0')
	{
		dest[leng] = src[leng];
		leng++;
	}
	dest[leng] = '\0';
	return (dest);
}

/**
 * _pathcat - Function that concatenates the variables passed path
 * and argument and returns a pointer with the content.
 * @argument: Program without route.
 * @route: Route of path.
 * Return: Pointer to new concatenate string.
 */
char *_pathcat(char *argument, char *route)
{
	char *conc = NULL;
	char *c = "/";

	conc = malloc(_strlen(argument) + _strlen(route) + 2);

	if (!conc)
		return (NULL);
	conc = _strcpy(conc, argument);
	conc = _strcat(conc, c);
	conc = _strcat(conc, route);
	return (conc);
}
