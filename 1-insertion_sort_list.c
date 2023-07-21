#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list
 *of integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *current_node;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		current_node = current;
		while (current_node && current_node->prev &&
		(current_node->prev->n > current_node->n))
		{
			temp = current_node->prev;
			current_node->prev = temp->prev;
			temp->next = current_node->next;

			if (temp->prev)
				temp->prev->next = current_node;

			if (current_node->next)
				current_node->next->prev = temp;

			temp->prev = current_node;
			current_node->next = temp;

			if (!current_node->prev)
				*list = current_node;

			print_list(*list);
		}
		current = current->next;
	}
}
