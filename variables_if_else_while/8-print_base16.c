#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char letter;

	n = 0;
	while (n <= 9)
	{
		putchar('0' + n);
		n++;
	}
	letter = 'a';
	while (letter <= 'f')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');

	return (0);
}
