#include "sort.h"

/**
 * insertion_sort_list - a C function that sorts a list using insertion
 * sorting algorithm
 * @list: A pointer to the head of list of integers
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted = NULL;
	listint_t *current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *insert_pos = sorted;

			while (insert_pos->next != NULL && insert_pos->next->n
					< current->n)
				insert_pos = insert_pos->next;

			current->next = insert_pos->next;
			if (insert_pos->next != NULL)
				insert_pos->next->prev = current;
			insert_pos->next = current;
			current->prev = insert_pos;
		}
		current = next;
	}

	*list = sorted;
}
