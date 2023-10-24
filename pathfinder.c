#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/* function to find path to executable */
char* pathfinder(char* command)
{
	/* get path to env */
	char* path = getenv("PATH");
	/* token pointer initialization */
	char* token = strtok(path, ":");
	/* buffer initialization to store the path */
	char path_buffer[1024];

	/* loop through directories in path */
	while(token != NULL)
	{
		/* create full path: combining the dir and the command */
		snprintf(path_buffer, sizeof(path_buffer), "%s/%s", token, command);
		/* check file is executable */
		if (access(path_buffer, X_OK) == 0)
		{
			/* return full path */
			return strdup(path_buffer);
		}
		/* move to the next dir in path and tokenize */
		token = strtok(NULL, ":");
	}
	/* if command not found */
	return NULL;
}
