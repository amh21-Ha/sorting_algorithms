#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


typedef struct array_s
{
	int *bg;
	int mid;
	int size;
} array_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */

typedef enum bool
{
		false = 0,
			true
} bool;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *rejoin(listint_t *list, listint_t *sorted);
listint_t *sorted_insert(listint_t *temp, listint_t **head);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void sorter(int *array, int start, int end, size_t size);
void swap(listint_t **store, listint_t **ptr, listint_t **list);
void swap_prev(listint_t **store, listint_t **temp, listint_t **list);
void shell_sort(int *array, size_t size);
size_t knuth_seq(size_t size);
void swap_int(int *a, int *b);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
array_t sort_helper(array_t sup_arr, int *space);
array_t merge(array_t sup_arr, array_t left, array_t right,
                int *space);
array_t create_array(int *array, int size, int start);
void print_merge(array_t left, array_t right);

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,		                size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

#endif /*_SORT_H_*/
