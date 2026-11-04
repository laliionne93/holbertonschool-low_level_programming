#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
static int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == ',' ||
		c == ';' || c == '.' || c == '!' || c == '?' ||
		c == '"' || c == '(' || c == ')' || c == '{' ||
		c == '}');
}

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z' &&
		    (i == 0 || is_separator(s[i - 1])))
			s[i] = s[i] - 32;
		i++;
	}

	return (s);
}
