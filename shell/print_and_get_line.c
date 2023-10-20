#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE -1
#define SUCCESSFUL 0
/**
 * ---Algorithm____
 * while in a loop
 * display $ to the stdout/screen
 * flush the buffer so that user can see the $
 * define the char *line = Null
 * size_t len = 0
 * ssize_t read;
 **/

int printscreen()
{
	printf("$ ");

	while(TRUE)
	{
		fflush(stdout);
		char *line = NULL;
		size_t len = 0;
		ssize_t read = getline(&line, &len, stdin);

		if (read == FALSE)
		{
			perror("failed to read input");
			free(line);
			break;
		}
		printf("%s\n", line);
		free(line);
	}
	return SUCCESSFUL;
}
