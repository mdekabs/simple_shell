#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int num_child = 5;
	pid_t child_pid;
	for (int i = 0; i < num_child; i++)
	{
		child_pid = fork();

		if(child_pid == -1)
		{
			perror("forking failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			char *argv[] = {"ls", "-l", "/tmp", NULL};
			char *envp[] = {NULL};
			printf("child %d executing ls -l /tmp:\n", i + 1);
			if (execve("/bin/ls", argv, envp) == -1)
			{
				perror("execve() failed");
				exit(EXIT_FAILURE);
			}
			else
			{
				int status;
				waitpid(child_pid, &status, 0);
				if(WIFEXITED(status))
				{
					printf("child %d excited with status: %d\n", i + 1, WEXITSTATUS(status));
				}
				else
				{
					printf("chid %d didnot exit normally.\n", i + 1);
				}
			}
		}
	}
	return 0;
}
