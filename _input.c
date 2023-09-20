#include "shell.h"

/**
 * _input - reads input from getline
 * @buff_size: buffer size
 * Return: buffer
 */

char *_input(size_t *buff_size)
{
	ssize_t ger;
	char *buff = NULL, **env;

	ger = getline(&buff, buff_size, stdin);
	if (ger == -1)
	{
		perror("Error(getline error)");
		free(buff);
		exit(EXIT_FAILURE);
	}
	while (*buff == ' ' || *buff == '\t' || *buff == '\n')
		buff++;
	if (_strcmp(buff, "exit\n") == 0)
	{
		free(buff);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(buff, "env\n") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	return (buff);
}
