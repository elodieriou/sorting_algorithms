#include "sort.h"
#include <stdio.h>

/**
 * bitonic_flow - Function that indicate the sorting direction
 * @flow: The sorting direction
 * Return: if flow = 1 return UP
 * if flow = 0 return DOWN
 */
char *bitonic_flow(int flow)
{
	if (flow == 1)
		return ("UP");
	else
		return ("DOWN");
}

/**
 * bitonic_swap - Function that swap the elements
 * @array: The array to sort
 * @i: an element of the array
 * @j: another element of the array
 * @flow: indicate the sorting direction
 * Return: Nothing
 */
void bitonic_swap(int *array, int i, int j, int flow)
{
	int tmp;

	if (flow == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * bitonic_merge - Function that sorts a bitonic sequence
 * if flow = 1, ascending sort
 * if direction = 0, descending sort
 * @array: The array to sort
 * @size: The size of the array
 * @nb: The number of elements to be sorted
 * @start: The start index
 * @flow: The direction to sort the elements
 * Return: Nothing
 */
void bitonic_merge(int *array, size_t size, int nb, size_t start, int flow)
{
	size_t i;
	int mid;

	if (nb > 1)
	{
		mid = nb / 2;
		for (i = start; i < start + mid; i++)
			bitonic_swap(array, i, i + mid, flow);
		bitonic_merge(array, size, mid, start, flow);
		bitonic_merge(array, size, mid, start + mid, flow);
	}
}

/**
 * bitonic_sequence - Function that produces a bitonic sequence
 * @array: The array to sort
 * @size: The size of the array
 * @nb: The number of element to be sorted
 * @start: The start index
 * @flow: The direction to sort the elements
 * Return: Nothing
*/
void bitonic_sequence(int *array, size_t size, int nb, size_t start, int flow)
{
	int mid;
	char *dir;

	if (nb > 1)
	{
		mid = nb / 2;
		dir = bitonic_flow(flow);

		printf("Merging [%d/%ld] (%s):\n", nb, size, dir);
		print_array(&array[start], nb);

		bitonic_sequence(array, size, mid, start, 1);
		bitonic_sequence(array, size, mid, start + mid, 0);
		bitonic_merge(array, size, nb, start, flow);

		printf("Result [%d/%ld] (%s):\n", nb, size, dir);
		print_array(&array[start], nb);
	}
}

/**
 * bitonic_sort - Function that sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
*/
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic_sequence(array, size, size, 0, 1);
}
