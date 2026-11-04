#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 *
 * Description: if the length is odd, prints the last
 * (length - 1) / 2 characters.
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
		len++;

	for (i = (len + 1) / 2; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
