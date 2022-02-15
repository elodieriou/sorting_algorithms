#include "sort.h"
#include <stdio.h>
/**
 * swap_nodes - Function that swaps two nodes
 * @list: The doubly linked list to sort
 * @tmp: The node that needs to be shifted
 * Return: tmp
 */
listint_t *swap_nodes(listint_t **list, listint_t *tmp)
{
	listint_t *save;

	if (tmp->prev->prev != NULL)
		tmp->prev->prev->next = tmp;
	tmp->prev->next = tmp->next;
	save = tmp->prev->prev;
	tmp->prev->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	tmp->next = tmp->prev;
	tmp->prev = save;
	if (tmp->prev == NULL)
		*list = tmp;
	return (tmp);
}
/**
 * cocktail_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: The doubly linked list to sort
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				tmp = swap_nodes(list, tmp->next);
				swapped = 1;
				print_list(*list);
			}
			tmp = tmp->next;
		}
		tmp = tmp->prev;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				tmp = swap_nodes(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else if (tmp->prev)
				tmp = tmp->prev;
		}
		tmp = tmp->next;
	}
}
