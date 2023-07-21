#include "sort.h"


/**
*insertion_sort_list - sorts a doubly linked list
*of integers in ascending order using the Insertion sort algorithm
* @list: pointer to the head of the list
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		while (current && current->prev && (current->prev->n > current->n))
		{
			prev = current->prev;
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				(*list) = current;

			print_list(*list);

		}
		current = current->next;
	}
}
