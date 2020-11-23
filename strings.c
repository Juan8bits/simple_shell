#include "header.h"

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

        while (s1[i] != 0 && s2[i] != 0) /*&& s1[i] == s2[i])*/
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
	short int i, j;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
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
	short int leng;

	while (src[leng] != '\0')
	{
		dest[leng] = src[leng];
		leng++;
	}
	dest[leng] = '\0';
	return (dest);
}
