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
 * Return: Nothing
 */
int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, 10);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, 10);
	}
	return (i + 1);
}
/**
 * lomuto - Function that sorts the array.
 * @array: The array to sort
 * @low: The first element of the array
 * @high: The last element of the array.
 * Return: Nothing
 */
void lomuto(int array[], int low, int high)
{
	int result;

	if (low < high)
	{
		result = partition(array, low, high);
		lomuto(array, low, result - 1);
		lomuto(array, result + 1, high);
	}
}
/**
 * quick_sort - Function that sorts an array of integers in ascending
 * order unsign the Quick sort algorithm.
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	lomuto(array, low, high);
}
