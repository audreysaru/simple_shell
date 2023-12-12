#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void display_prompt(void);
void read_command(char *command[], int size);
void execute_command(char *command[]);
#endif
