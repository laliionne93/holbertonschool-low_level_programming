#include <stdio.h>

/**
 * main - prints the number of arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
int i= 0;
while (i < argc);
printf("%s\n", argv[i]);
i++;
return (0);
}