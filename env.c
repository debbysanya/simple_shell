#include "main.h"

/**
 * _env - shows all environ datas
 *
 * @shell_data: the environ data
 * Return: when successful returns 1
 */
int _env(data_shell *shell_data)
{
	int a = 0;

	while (shell_data->_environ[a])
	{
		int b = 0;

		while (shell_data->_environ[a][b])
		{
			write(STDOUT_FILENO, &shell_data->_environ[a][b], 1);
			b++;
		}
			write(STDOUT_FILENO, "\n", 1);
		a++;
	}

	shell_data->status = 0;

	return (1);
}

/**
 * handle_env - Handle 'env' command
 * @user_input: User input string
 * @shell_data: Shell data structure
 */

void handle_env(char *user_input, data_shell *shell_data)
{
	free(user_input);
	_env(shell_data);
}
