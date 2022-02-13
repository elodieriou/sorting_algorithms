#include "sort.h"

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

/**
 * shell_sort - Function that sorts an array of integers
 * in ascending order using the Shell sort algorithm, using
 * the Knuth sequence
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int value;

	if (size < 2)
		return;

	while (interval < size / 3)
		interval *= 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j >= interval && array[j - interval] > value)
			{
				swap(&array[j], &array[j - interval]);
				j -= interval;
			}
			array[j] = value;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
