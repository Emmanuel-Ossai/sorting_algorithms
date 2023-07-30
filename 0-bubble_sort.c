#include "sort.h"

/**
 * swap_ints - a C function that swap integers of an array
 * @m: first integer
 * @n: second integer
 */
void swap_ints(int *m, int *n)
{
	int swapped;

	swapped = *m;
	*m = *n;
	*n = swapped;
}

/**
 * bubble_sort - a C function that sort integers upwards
 * @array: array of integers
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
