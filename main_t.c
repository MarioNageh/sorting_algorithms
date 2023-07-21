#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

listint_t *create_listintt(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}
listint_t *create_listint(const int *a, size_t n)
{
	listint_t *list, *node, *head;
	int i;
	int *tmp;
	for (i = 0; i < n; i++)
	{
		node = (listint_t *)malloc(sizeof(listint_t));
		if (!node)
			return (NULL);

		tmp = (int *)&node->n;
		*tmp = a[i];
		node->next = NULL;
		node->prev = NULL;

		if (list == NULL)
		{
			list = node;
			head = list;
		}
		else
		{
			node->prev = list;
			list->next = node;
			list = list->next;
		}
	}
	return head;
}

int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	// print_list(list);
	// printf("\n");
	insertion_sort_list(&list);
	// printf("\n");
	// print_list(list);
	return (0);
}
