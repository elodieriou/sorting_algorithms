#include "sort.h"
#include <stdio.h>

/**
 * max_array - Function that get the max size of an array
 * @array: The array
 * @size: The size of the array
 * Return: Nothing
 */
int max_array(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - Function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	int max, *count, *output, i;

	if (size < 2)
		return;

	max = max_array(array, size) + 1;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc((max) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize count array with all zero */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Store the count for each element */
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	/* Store the cumulative count of each array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max);

	 /* Find the index of each element of the original array in count array */
	 /* And place the elements in output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	/* Copy the sorted elements into original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
