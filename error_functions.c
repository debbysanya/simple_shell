#include "main.h"

/**
 * _errputs - Print a string to the standard error
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _errputs(char *str)
{
	int a;

	if (!(str))
	{
		return (0);
	}
	for (a = 0; str[a]; a++)
	{
		write(2, &str[a], 1)
	}

	return (a);
}

/**
 * print_error - Print an error message to the standard error
 * @av: The array of command and arguments
 * @err: The error message to be printed
 */
void print_error(char **av, char *err)
{
	_errputs(_getenv("_"));
	_errputs(": 1 :");
	_errputs(av[0]);
	_errputs(": ");
	_errputs(err);
}
