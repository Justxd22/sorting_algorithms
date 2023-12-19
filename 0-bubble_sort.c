#include "sort.h"

/**
 * bubble_sort - Bubble Sort algo.
 * 
 * @array: The array to be sorted.
 * @size: The size of the array.
 * No Return
 */
void bubble_sort(int *array, size_t size)
{
    size_t x, y;
    int t, swap;

    if (array == NULL || size < 2)
        return;

    for (x = 0; x < size - 1; x++)
    {
        swap = 0;
        for (y = 0; y < size - x - 1; y++)
        {
            if (array[y] > array[y + 1])
            {
                t = array[y];
                array[y] = array[y + 1];
                array[y + 1] = t;
                swap = 1;
                print_array(array, size);
            }
        }
        if (swap == 0)
            break;
    }
}
