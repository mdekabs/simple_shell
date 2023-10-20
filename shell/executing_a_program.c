#include<stdio.h>
#include<unistd.h>
#define FAILED -1
#define SUCCESSFULL 0
/**
 * main --- execve example: executes a programme
 *
 * return: 0.
 */

int main()
{
	char* argv[] = {"/bin/ls", NULL}; /* pointer to array of arguments*/
	printf("before execve\n");
	/* check if no argument passed to the programme */
	if (execve(argv[0], argv, NULL) == FAILED)
	{
		perror("Error: no argument found");
	}
	printf("After execve\n");
	return SUCCESSFULL;
}
