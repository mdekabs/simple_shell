#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include "tokenizer.h"
#include "tokenizer.c"
#include "pathfinder.c"
#include "pathfinder.h"
#include "env.h"
#define MAX_ARGUMENTS 10
#define MAX_LEN 100
#define TRUE 1
#define UNSUCCESSFULL 1
#define SUCCESSFULL 0

extern char **environ;

int main()
{
	char command[MAX_LEN];
	char *arguments[MAX_ARGUMENTS];


	while(TRUE)
	{
		printf("welcome to my shell> ");
		/* check if endoffile then print new line */
		if (fgets(command, MAX_LEN, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		/* remove trailing newline char if len of str
		 *  == null but > than 0*/
		ssize_t len = strlen(command);
		if(len > 0 && command[len - 1] == '\n' )
		{
			command[len - 1] = '\0';
		}

		/* check if command is "exit" then call the function */
		if (strcmp(command, "exit") == 0)
		{
			handle_exit();
		}

		/* parse the arguement */

		tokenize(command, arguments, MAX_ARGUMENTS);

		char *executable = pathfinder(arguments[0]);

		if(executable == NULL)
		{
			fprintf(stderr, "simple_shell: command not found: %s\n", command);
			continue;
		}
		/* execute command */
		pid_t child_pid = fork();
		if(child_pid == 0)
		{
			char *argv[] = {command, NULL};
			execve(command, arguments, environ);

			fprintf(stderr, "simple_shell: command not found: %s\n", command);
			exit(UNSUCCESSFULL);
		}
		else if (child_pid < 0)
		{
			perror("simple_shell");
			exit(UNSUCCESSFULL);
		}
		else
		{
			/* wait and return to the parent process */
			int status;
			wait(&status);
		}
		free(executable);
	}
	return SUCCESSFULL;
}
