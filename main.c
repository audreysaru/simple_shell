#include <stdio.h>
#include "shell.h"

/**
 * main - commands to run
 *
 * Return: 0
 */

int main(void)
{
	char *command[10];

	while (1)
	{
		display_prompt();
		read_command(command, sizeof(command) / sizeof(command[0]));
		execute_command(command);
	}

	return (0);
}
