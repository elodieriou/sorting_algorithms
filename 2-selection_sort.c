#include "sort.h"
/**
 * selection_sort - Function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, mini;

	for (i = 0; i < size - 1; i++)
	{
		mini = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[mini])
				mini = j;
		if (array[i] != array[mini])
		{
			swap(&array[mini], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps the value of a and b
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
