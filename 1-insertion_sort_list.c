#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list.
 * 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node_in_list;

	if (!list || !*list || !(*list)->next)
		return;

	current = next_node_in_list = (*list)->next;

	while (next_node_in_list)
	{
		next_node_in_list = next_node_in_list->next;

		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}
		current = next_node_in_list;
	}
}
