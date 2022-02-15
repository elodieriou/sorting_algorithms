#include "sort.h"
#include <stdio.h>
/**
 * merge_top_down - Function that sort a subarray
 * @array: The subarray of an array to sort
 * @output: A copy of the array sorted
 * @start: The beginning index of the array
 * @mid: The middle index of the array
 * @end: The end index of the array
 * Return: Nothing
 */
void merge_top_down(int *array, int *output,
		    size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = 0;

	while (i < mid && j < end)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			k++;
			i++;
		}
		else
		{
			output[k] = array[j];
			k++;
			j++;
		}
	}
	while (i < mid)
	{
		output[k] = array[i];
		k++;
		i++;
	}
	while (j < end)
	{
		output[k] = array[j];
		k++;
		j++;
	}
	for (i = start, k = 0; i < end; i++)
	{
		array[i] = output[k];
		k++;
	}
}

/**
 * merge_print_step - Function that prints the steps of merging
 * @array: The array to be sorted
 * @output: The copy of the array
 * @start: The start index of the array
 * @mid: The middle index of the array
 * @end: The end index of the array
 * Return: Nothing
 */
void merge_print_step(int *array, int *output,
		      size_t start, size_t mid, size_t end)
{
	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	merge_top_down(array, output, start, mid, end);

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_recursion - Function that use the recursion concept to merge
 * @array: The subarray of an array to sort
 * @output: A copy of the array sorted
 * @start: The start index of the array
 * @end: The end index of the array
 * Return: Nothing
 */
void merge_recursion(int *array, int *output, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_recursion(array, output, start, mid);
		merge_recursion(array, output, mid, end);
		merge_print_step(array, output, start, mid, end);
	}
}

/**
 * merge_sort - Function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *output;

	if (size < 2)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	merge_recursion(array, output, 0, size);
	free(output);
}
