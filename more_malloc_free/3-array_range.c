#include "main.h"

/**
 * array_range - creates an array of integers from min to max
 * @min: first value (included)
 * @max: last value (included)
 *
 * Return: pointer to the new array, or NULL
 */
int *array_range(int min, int max)
{
	int *a;
	int i, size;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	a = malloc(sizeof(int) * size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		a[i] = min + i;
	return (a);
}
