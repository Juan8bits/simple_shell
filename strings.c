#include "header.h"

/**
 * _strcmp
 *
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
 * _getenv - 
 * @name: Name of enviroment variale.
 * Return: Pointer to environ variable founded.
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
