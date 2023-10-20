#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define EXIST_FAILURE -1
#define SUCCESSFUL 0

/**
 * this function split a string into words and return 
 * the array of those words
 **/


/* this function is to split string */
char** splitString(const char* input, int* wordCount)
{
	*wordCount = 0;
	const char* delimiter = " "; /* space as delimiter */
	char* inputCopy = strdup(input);

	if (inputCopy == NULL)
	{
		perror("error in allocation");
		exit(EXIT_FAILURE);
	}

	/* tokenization */
	char* token = strtok(inputCopy, delimiter);
	while (token != NULL)
	{
		(*wordCount)++;
		token = strtok(NULL, delimiter);
	}
	
	/* cast and allocate memory to the words */
	char** words = (char**)malloc(*wordCount * sizeof(char*));
	if (words == NULL)
	{
		perror("error in allocating memory");
		exit(EXIT_FAILURE);
	}

	int i;
	token = strtok(inputCopy, delimiter);

	/* loop thro the token set to array */
	while(token != NULL)
	{
		words[i] == strdup(token);
		if (words[i] == NULL)
		{
			perror("error allocating memory");
			exit(EXIT_FAILURE);
		}

		i++;
		token = strtok(NULL, delimiter);
	}

	/* free memory allocated */
	free(inputCopy);
	return words;
}

/* function to free the words */
void freeWords(char** words, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
	{
		free(words[i]);
	}
	free(words);
}

//int main()
//{
//	printf("programme run successfully\n");
//	return 0;
//}
