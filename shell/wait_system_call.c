
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/**
 * main - fork & wait function
 * return 0;
 */

int wait_fun()
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error processing");
//		return 1;
	}
	if(child_pid == 0)
	{
		printf("wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("oh, its all better now\n");
	}
//	return 0;
}
