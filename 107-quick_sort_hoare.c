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
 * partition - Divides the array into little unsorted parts.
 * @array: The array to sort
 * @low: The first element of the array
 * @high: The last element of the array
 * @size: The size of the array
 * Return: -1 or j
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		if (i != j)
			print_array(array, size);
	}
	return (-1);
}
/**
 * hoare - Function that sorts the array.
 * @array: The array to sort
 * @low: The first element of the array
 * @high: The last element of the array.
 * @size: The size of the array
 * Return: Nothing
 */
void hoare(int *array, int low, int high, size_t size)
{
	int result;

	if (low < high)
	{
		result = partition(array, low, high, size);
		hoare(array, low, result, size);
		hoare(array, result + 1, high, size);
	}
}
/**
 * quick_sort_hoare - Function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low, high;

	if (size < 2)
		return;
	low = 0;
	high = size - 1;
	hoare(array, low, high, size);
}
