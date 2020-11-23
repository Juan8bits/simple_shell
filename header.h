#ifndef SHELL_BASIC_H
#define SHELL_BASIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

/* Environment variables */
extern char **environ;
char *_getenv(char *name);

/* Functions for strings */
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **get_pointers_array(char *line, char *limit);
char *_pathcat(char *argument, char *route);

/* Create and execute new process */
int new_process(char **argument);
void status_exec(char **argument);

#endif
