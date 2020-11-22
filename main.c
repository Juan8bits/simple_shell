#include "header.h"

/**
 * _strlen - !!!!!!!!!!!
 * @s:
 * Return: size of string.
 */

int _strlen(char *s)
{
	int z = 0;

	while (s[z] != '\0')
		z++;
	return (z);
}

/**
 * get_pointers_array - !!!!
 * @limit:
 * @line:
 * Return:
 */

char **get_pointers_array(char *line, char *limit)
{
/*const char limit[2] = " ";*/
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

/*Count limit char*/
	for (i = 0; line[i] != 0; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}
/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 2));
/*Full array*/
	array[0] = strtok(line, limit);
	for (i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
	}
	array[i] = NULL;
/* Function to do new process*/
/*newprocess(array);*/
	return (array);
}

/**
 * main -
 *
 * Return: 0 on succesfull
 */

int main(void)
{
	char *line = NULL;
	char *prompt = "#cisfun$ ";
	char *delim = " ";
	char **av = NULL;
	size_t size_line = 0;
	ssize_t retgetline = 0;
	int prueba = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		retgetline = getline(&line, &size_line, stdin);

		if (retgetline == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (retgetline == -1)
			perror("ERROR: ");
		else
		{
			av = get_pointers_array(line, delim);
	
			while (av[prueba])
			{
				printf("%s[%d]\n", av[prueba], prueba);
				prueba++;
			}
			prueba = 0;
			new_process(av);
		}
	}
	free(line);
	free(av);
	return (0);
}
