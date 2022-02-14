#include "sort.h"
#include <stdio.h>
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
 * heap - Creates a heap
 * @array: The array
 * @n: The size of the heap
 * @i: Takes an integer value
 * @size: The size of the array
 * Return: Nothing
 */
void heap(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heap(array, n, largest, size);
	}
}
/**
 * heap_sort - Function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: The array
 * @size: The size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heap(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heap(array, i, 0, size);
	}
}
