#include "header.h"

/**
 * sig_handler - Function called when an interrupt signal happen
 * @sig_c: Value of interrupt signal.
 */
void sig_handler(int sig_c)
{
	if (sig_c == SIGINT)
		write(STDOUT_FILENO, "\n", 11);
}

/**
 * get_pointers_array - Function that become a string in
 * pointers array separated by limit variable.
 * @limit: Limit character.
 * @line: Pointer to string to separate.
 * Return: Pointer to pointers array.
 */

char **get_pointers_array(char *line, char *limit)
{
	int i, j;/*Runer*/
	int contdelim = 0;/*Counter limit*/
	char **array = NULL;

/*Count limit char*/
	for (i = 0; line[i] && line; i++)
	{
		for (j = 0; limit[j]; j++)
		{
			if (line[i] == limit[j])
				contdelim++;
		}
	}
/*Allocate memory*/
	array = malloc(sizeof(char *) * (contdelim + 2));
	if (!array)
	{
		return (NULL);
	}
/*Full array*/
	array[0] = strtok(line, limit);
	for (i = 1; i <= contdelim; i++)
	{
		array[i] = strtok(NULL, limit);
	}
	array[i] = NULL;
/* Function to do new process*/
/*newprocess(array);*/
	return (array);
}

/**
 * main - Main function
 * Return: 0 on succesfull
 */

int main(void)
{
	char *line = NULL;
	char *prompt = "#cisfun$ ";
	char *delim = " \t\n";
	char **av = NULL;
	size_t size_line = 0;
	ssize_t retgetline = 0;
	int status = 1;

	signal(SIGINT, sig_handler);
	while (status)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		retgetline = getline(&line, &size_line, stdin);

		if (retgetline == EOF)
		{
			free(line);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else if (retgetline == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			perror("./shell");
		}
		else if (*line != 10)
		{
			av = get_pointers_array(line, delim);
			status = new_process(av);
		}
	}
	free(line);
	return (0);
}
