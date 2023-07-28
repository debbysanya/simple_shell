#include "main.h"
/**
 * handle_built_in_commands - Handles built-in commands of the shell
 * @receive_argv: Array of tokens from user input
 * @shell_data: Structure containing shell data
 * Return: 1 if the command is built-in, 0 otherwise
 */
int handle_built_in_commands(char **receive_argv, data_shell *shell_data)
{
	if (_strcmp(receive_argv[0], "env") == 0)
	{
		_env(shell_data);
		return (1);
	}
	if (_strcmp(receive_argv[0], "env") == 0)
	{
		exit_shell(receive_argv, shell_data->status);
		return (1);
	}

	return (0);
}

/**
 * shell_loop - Main loop of the shell clone
 * @shell_data: Structure containing shell data
 * Return: return 0
 */
int shell_loop(data_shell *shell_data)
{
	char *user_input, **receive_argv;
	ssize_t fd_check;
	int i;

	while (1)
	{
		user_input = NULL;
		fd_check = 0;
		user_input = prompt(&fd_check);
		receive_argv = tokenization(user_input, receive_argv, fd_check);
		if (receive_argv[0] == NULL)
			continue;

		if (handle_built_in_commands(receive_argv, shell_data))
		{
			free(user_input);
			free_array(receive_argv);
			continue;
		}

		i = handle_env_commands(receive_argv);
		if (i != 0)
		{
			free(user_input);
			free_array(receive_argv);
			continue;
		}
		shell_data->status = execute_command(receive_argv);
		if (shell_data->status == 1)
			print_error(receive_argv, "not found\n");
		free(user_input);
		free_array(receive_argv);
	}
	return (0);
}

/**
 * main - Entry point of the shell program
 * @ac: Argument count
 * @argv: Array of pointers to strings
 * Return: Return 1 or 0
 */
int main(int ac, char **argv)
{
	data_shell shell_data;

	shell_data._environ = environ;
	shell_data.status = 0;

	(void)ac;
	(void)argv;

	shell_loop(&shell_data);

	return (0);
}
