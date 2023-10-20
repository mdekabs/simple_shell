#include"print_and_get_line.c"
#include "split_string.c"
#include"fork_process.c"
#include"executing_a_program.c"
#include"wait_system_call.c"

int main()
{
	printscreen();
	splitString();
	fork();
	execute();
	wait_fun();
	return 0;
}
