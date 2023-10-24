#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "env.h"

void print_environment()
{
	extern char **environ;
	for (char** env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
