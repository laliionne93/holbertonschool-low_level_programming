#include "function_pointers.h"

/**
 * array_interator -exercice a functions on each array elemnet
 *@array: the array
 *@size: size of the array
 *@action: pointer to the function to use 
 *
 *Return Nothing.
 */
 void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}