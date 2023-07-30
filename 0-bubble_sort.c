#include "sort.h"

/**
 * swap_ints - a C function that swaps two integers
 * @k: Pointer to the first integer to swap.
 * @l: Pointer to the second integer to swap.
 */
void swap_ints(int *k, int *l)
{
	int tmp;

	tmp = *k;
	*k = *l;
	*l = tmp;
}

/**
 * bubble_sort - a C function that sorts an array of integers in
 * ascending order using Bubble Sort.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	bool swapped;

	do {
		swapped = false;
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				swapped = true;
			}
		}
		size--;
	} while (swapped);
}
