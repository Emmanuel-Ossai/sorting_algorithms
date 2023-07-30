#include "sort.h"

/**
 * swapper - a C function that swap integers
 * @m: first integer
 * @n: second integer
 */

void swapper(int *m, int *n)
{
	int swapped;

	swapped = *m;
	*m = *n;
	*n = swapped;
}

/**
 * selection_sort - a C function that sort integers upwards using selection
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (y = x + 1; y < size; y++)
			min = (array[y] < *min) ? (array + y) : min;

		if ((array + x) != min)
		{
			swapper(array + x, min);
			print_array(array, size);
		}
	}
}
