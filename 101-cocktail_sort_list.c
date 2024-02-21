#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list);


/**
 * swap_node - swaps the positon of two node in a doubly
 * linked list
 * @_nodea: node to push to back
 * @_nodeb: node to push to front
 * @list: list to sort
 */
void swap_node(listint_t **_nodea, listint_t **_nodeb,
		listint_t **list)
{
	listint_t *node_a, *node_b, *temp1, *temp2;

	if (!_nodea || !_nodeb)
		return;
	node_a = *_nodea;
	node_b = *_nodeb;
	if (!node_a || !node_b)
		return;
	temp1 = node_a->prev;
	temp2 = node_b->next;

	node_a->next = temp2;
	node_a->prev = node_b;
	node_b->next = node_a;
	node_b->prev = temp1;

	if (temp1)
		temp1->next = node_b;
	else
		*list = node_b;
	if (temp2)
		temp2->prev = node_a;
}
/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - sorts a list using the cocktail
 * algorithm and prints out the list after each swap
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
    listint_t *list2, *temp;
    int swapped;

    if (!list || !(*list) || !(*list)->next)
        return;

    temp = *list;

    for (; temp; temp = temp->next)
    {
        list2 = temp;
        swapped = 0;

        while (list2)
        {
            temp = list2;
            list2 = list2->next;

            if (!list2)
                break;

            if (temp->n > list2->n)
            {
                swap_node(&temp, &list2, list);
                swapped = 1;
            }
        }

        list2 = temp;

        while (list2)
        {
            temp = list2;
            list2 = list2->prev;

            if (!list2)
                break;

            if (temp->n < list2->n)
            {
                swap_node(&list2, &temp, list);
                swapped = 1;
            }
        }

        print_list(*list);

        if (!swapped)
            break;
    }
}
