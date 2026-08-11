#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quicksort.
 * @array: Pointer to the array of integers to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition (pivot).
 * @size: Total size of the array for printing.
 *
 * Return: Index of the pivot after partitioning.
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low, j;
	int tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - Recursively sorts sub-arrays using quicksort.
 * @array: Pointer to the array of integers to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Total size of the array.
 */
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, p - 1, size);
		lomuto_sort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto scheme).
 * @array: Pointer to the array of integers to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, (ssize_t)size - 1, size);
}
