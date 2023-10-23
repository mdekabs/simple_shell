#include <stdio.h>
#include<string.h>
/* function to parse str into args */
void tokenize(char* command, char* arguments[], int max_args)
{
	char* token = strtok(command, " ");
	int arg_count = 0;

	/* loop */
	while(token != NULL && arg_count < max_args - 1)
	{
		/* set the args to token and parse it*/
		arguments[arg_count] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	arguments[arg_count] = NULL;
}
