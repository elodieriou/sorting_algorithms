#include "sort.h"
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
void radix_counting_sort(int *array, size_t size, int place)
{
    int max, *count, *output, i;

    if (size < 2)
        return;

    output = malloc(sizeof(int) * size + 1);
    if (output == NULL)
        return;
    max = (array[0] / place) % 10;

    for (i = 1; i < (int)size; i++)
        if(((array[i] / place) % 10) > max)
            max = array[i];

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    /* Initialize count array with all zero */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Calculate count of elements */
    for (i = 0; i < (int)size; i++)
        count[(array[i] / place) % 10] += 1;

    /* Calculate cumulative count */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Place the elements in sorted order */
    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10] -= 1;
    }

    /* Copy the sorted elements into original array */
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * radix_sort - Function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
    int max, place;

    /* Get maximum element */
    max = max_array(array, size);

    /* Apply counting sort to sort elements based on place value */
    for (place = 1; max / place > 0; place *= 10)
    {
        radix_counting_sort(array, size, place);
        print_array(array, size);
    }
}
