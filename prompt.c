#include "main.h"
/**
 * prompt - read prompts and displays inputs
 * @fd_check: the number of byte read by getline
 * Return: User_input
 */

char *prompt(ssize_t *fd_check)
{
	char *prompt_display = "Cisfun$";
	char *user_input = NULL;

	if (user_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write_char('\n');
		exit(EXIT_SUCCESS);
	}
	*fd_check = s_len(user_input);

	if (*fd_check == -1 && isatty(STDIN_FILENO))
	{
		write_char('\n');
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	else if (*fd_check == -1)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	if (*fd_check == 0 && isatty(STDIN_FILENO))
	{
		free(user_input);
		return (prompt(fd_check));
	}
	/*write(STDOUT_FILENO, user_input, byte_size);*/
	user_input[_strcspn(user_input, "\n")] = '\0';
	return (user_input);
}
