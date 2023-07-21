#include "sort.h"


/**
*insertion_sort_list - sorts a doubly linked list
*of integers in ascending order using the Insertion sort algorithm
* @list: pointer to the head of the list
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *current_node;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		current_node = current;
		while (current_node && current_node->prev
		&& (current_node->prev->n > current_node->n))
		{
			prev = current_node->prev;
			prev->next = current_node->next;
			if (current_node->next)
				current_node->next->prev = prev;

			current_node->next = prev;
			current_node->prev = prev->prev;
			prev->prev = current_node;
			if (current_node->prev)
				current_node->prev->next = current_node;
			else
				(*list) = current_node;

			print_list(*list);

		}
		current = current->next;
	}
}
