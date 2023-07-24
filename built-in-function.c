#include "main.h"
/**
 * exit_shell - this function exits the simple_shell
 * @receive_argv: this is the cmd entered
 * @execution_status: this is the status of the exit function
 *
 * Return: returns nothing when the shell is exited
 */
void exit_shell(char **receive_argv, int execution_status)
{
	char **cmds = NULL;
	int a = 0, arg;
	const char *error_msg = "Cisfun$: too many arguments\n";

	while (receive_argv[a] != NULL)
		a++;
	{
		if (a == 1)
		{
			free_array(receive_argv);
			free(cmds);
			exit(execution_status);
		}
		else if (a == 2)
		{
			arg = _atoi(receive_argv[1]);
			if (arg < 0)
			{
				print_error(receive_argv, "illegal number:");
				_errputs(receive_argv[1]);
				_errputs("\n");
			}
			else
			{
				free_array(receive_argv);
				free(cmds);
				exit(arg);
			}
		}
			else
				write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}
