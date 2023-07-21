#include "sort.h"


/**
*insertion_sort_list - sorts a doubly linked list
	of integers in ascending order using the Insertion sort algorithm
* @list: pointer to the head of the list
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp_head, *current, *prev;

	if (!list && !((*list)->next))
		return (NULL);

	current = (*list)->next;
	head = *list;

	tmp_head = (listint_t *)malloc(sizeof(listint_t));
	tmp_head->prev = NULL;
	tmp_head->next = NULL;

	while (current)
	{
		while (current->prev && (current->prev->n > current->n))
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
