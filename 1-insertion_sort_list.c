#include "sort.h"

/**
 * list_swapper - a c function that swap nodes in a list
 * @h: list head.
 * @n1: first node.
 * @n2: second node
 */
void list_swapper(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - a C function that sort lists using the insertion sort
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = swapped)
	{
		swapped = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			list_swapper(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
