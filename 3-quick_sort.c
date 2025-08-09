#include "sort.h"

/* Function prototypes */
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively applies Lomuto partition scheme
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j && array[i] != array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}
