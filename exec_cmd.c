#include "shell.h"

/**
 * exec_cmd - executes the inputted command
 * @tokens: array of the splited string
 * Return: void
 */

void exec_cmd(char *tokens[])
{
	pid_t child;
	int stats;

	child = fork();
	if (child == -1)
	{
		perror("Error(fork fails)");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	if (waitpid(child, &stats, 0) == -1)
	{
		perror("Error(wait error)");
		exit(EXIT_FAILURE);
	}
}
