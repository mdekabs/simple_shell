#include<string.h>
#include"prompt.c"
#include "split_string.c"
#include"fork_process.c"
#include"executing_a_program.c"
#include"wait_system_call.c"
#define TRUE 1

int main()
{
	char input[1024];
	char **words;
	int wordCount;
	
	while(TRUE)
	{
		printscreen();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		words = splitString(input, &wordCount);
		
		if(wordCount >0)
		{
			if(strcmp(words[0], "execute") == 0)
			{
				execute();
			}
			else if (strcmp(words[0], "fork") == 0)
			{
				fork();
			}
			else if(strcmp(words[0], "wait_fun") == 0)
			{
				wait_fun();
			}
			else if (strcmp(words[0], "exit") == 0)
			{
				break;
			}
			else
			{
				printf("no command found: '%s\n'", words[0]);
			}
		}

		freeWords(words, wordCount);
	}
	printf("exiting shell...\n");

	return 0;
}
