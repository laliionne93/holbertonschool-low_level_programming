#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description: takes into account all the - and + signs before
 * the number. Returns 0 if there are no numbers in the string.
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 - (s[i] - '0');
		i++;
	}

	if (sign == 1)
		return (-num);
	return (num);
}
