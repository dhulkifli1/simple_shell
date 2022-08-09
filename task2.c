#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#include <string.h>

/**
 * main - entry to the program
 *
 */
void main()
{
	char * input;
	size_t bufSize = 32;
	size_t characters;
	char *argv[] = {"cmd"};
	char *envp[] ={NULL};
	char *d = " ";
	char *portion;

	while (1)
	{
		input = NULL;
		write(STDOUT_FILENO,"#cisfun$ ",9);
		characters = getline(&input,&bufSize,stdin);
		sanitizeInput(&input, characters);
		portion = strtok(input, d);
		while (portion != NULL)
		{
			if(fork()!=0)
			{
				wait(NULL);
			}
			else
			{
				if (execve(portion,argv,envp) == -1)
				{
					perror("./shell");
					exit(0);
				}
			}
			portion = strtok(NULL, d);
		}
	}
}


/**
 * sanitizeInput - Removes \n at the end of line and
 *                 checks if we can read a new line
 * @input - input string from stdin
 * @characters - no of characters read or -1 if error
 */
void sanitizeInput(char **input, size_t characters)
{
	char *tempString = *input;
	char *buf;

	if(characters == -1)
	{
		exit(0);
	}

	while (*tempString)
	{
		if (*tempString == 10)
		{
			*tempString = 0;
		}
		++tempString;
	}
}

