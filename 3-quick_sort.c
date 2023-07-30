#include "sort.h"

void swapper(int *m, int *n);
int lomuto(int *array, size_t size, int left, int right);
void sort_lom(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swapper - a C function that swap integers
 * @m: first intege
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
 * lomuto - a c function that sorts to lomuto partition scheme
 * @array: array
 * @size: size
 * @left: start of index
 * @right: end of index
 *
 * Return: 0
 */
int lomuto(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swapper(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swapper(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * sort_lom - a C function that performs recursive quicksort
 * @array: array
 * @size: size
 * @left: start of index
 * @right: end of index
 */
void sort_lom(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto(array, size, left, right);
		sort_lom(array, size, left, belong - 1);
		sort_lom(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - a C function that sort fast in ascending order
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_lom(array, size, 0, size - 1);
}
