#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: Pointer to the array of integers to sort.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	int tmp, swapped;

	if (array == NULL || size < 2)
		return;

	len = size;
	while (len > 1)
	{
		swapped = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		len--;
	}
}
