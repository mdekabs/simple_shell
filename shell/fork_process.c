#include<stdio.h>
#include<unistd.h>
#define FAILED -1
#define ERROR 1
#define SUCCESSFULL 0

/**
 * main -- demo of fork example
 * return 0
 */
int
fork()
{	
	/* initialization */
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork(); /* create a child process */
	/* check for conditions */
	if (child_pid == FAILED)
	{
		perror("error: ");
		return 1;
	}
	my_pid = getpid();
	printf("my parent process is %u\n", my_pid);
	if (child_pid == SUCCESSFULL)
	{
		printf("(%u) nope!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, i am the parent\n", my_pid, child_pid);
	}
	return SUCCESSFULL;
}
