#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: sorted array or nothing if Null
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_idx;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	while (i < size)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] && array[j] < array[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
