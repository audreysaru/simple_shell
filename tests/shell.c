#include "shell.h"

/**
 * display_prompt - display text
 * read_command - reads array of characters
 * execute_command - executes commands
 */

void display_prompt(void)
{
	printf("$ ");
}

void read_command(char *command[], int size)
{
	char input[100];
	char *token = strtok(input, " ");
	int i = 0;

	gets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	while (token != NULL && i < size - 1)
	{
		command[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	command[i] = NULL;
}

void execute_command(char *command[])
{
	if (command[0] != NULL)
	{
		if (strcmp(command[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
			else if (strcmp(command[0], "env") == 0)
			{
				char **env = environ;

				while (*env)
				{
					printf("%s\n", *env);
				env++;
				}
			}
		else
		{
			if (command[0] != NULL)
			{
				if (access(command[0], X_OK) == 0)
				{
					execvp(command[0], command);
				}
				else
				{
					char *path = getenv("PATH");
					char *token = strtok(path, ":");

					while (token != NULL)
					{
						char command_path[100];

						strcpy(command_path, token);
						strcat(command_path, "/");
						strcat(command_path, command[0]);
					if (access(command_path, X_OK) == 0)
					{
					execvp(command_path, command);
					break;
					}

					token = strtok(NULL, ":");
					}

					printf("Command not found: %s\n", command[0]);
				}
			}
		}
	}
}
