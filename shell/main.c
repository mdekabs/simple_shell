#include<string.h>
#include"prompt.c"
#include "split_string.c"
#include"fork_process.c"
#include"executing_a_program.c"
#include"wait_system_call.c"
#define TRUE 1
#define SUCCESSFULL 0

/* create a structure for my commands */
typedef int (*commandFunction)();

//define struct
typedef struct {
	const char* command;
	commandFunction function;
} commandMapping;

/* make a list of the commands to map */
commandMapping commandMappings[] = {
	{"execute", execute},
	{"fork", fork},
	{"wait_fun", wait_fun}
};


int main()
{
	char* input = NULL;
	char **words;
	int wordCount;
	int i;
	
	while (TRUE)
	{
		printscreen();
		if (getline(&input, &(size_t){0}, stdin) == ERROR)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		words = splitString(input, &wordCount);


		if (wordCount > 0) {
			int commandFound = 0;
			for (i = 0; i < sizeof(commandMappings) / sizeof(commandMappings[0]); i++)
			{
				if(strcmp(words[0], commandMappings[i].command) == 0)
				{
					commandFound = 1;
					int result = commandMappings[i].function();
					if (result !=0)
					{
						printf("failed execution. %s\n", words[0]);
					}
					break;
				}
			}
			if (!commandFound)
			{
				printf("No command:  '%s'\n", words[0]);
			}
		}

		freeWords(words, wordCount);
	}
	free(input);
	printf("exiting shell ....\n");
	return 0;
}
