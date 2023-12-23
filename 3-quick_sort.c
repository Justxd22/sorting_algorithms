#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_recursive - Recursive function to do quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high], pivot_index;
		int i = low - 1, j;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}

		swap(&array[i + 1], &array[high]);
		print_array(array, size);

		pivot_index = i + 1;

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick Sort
 * @array: array to sort
 * @size: array size
 * No Return
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
