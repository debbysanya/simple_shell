#include "main.h"
/**
 * _print - function that prints an input string
 * @str: string to be printed
 * Return: 0
 */
void _print(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		write_char(str[a]);
		a++;
	}
}
/**
 * write_char - function that writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_char(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
