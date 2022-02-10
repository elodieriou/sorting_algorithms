#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *tmp = *list;
	listint_t *next = NULL;

	while (tmp != NULL)
	{
		next = tmp->next;
		tmp->prev = NULL;
		tmp->next = NULL;
        printf("hello")
		sorted_insertion(&sorted, tmp);

		tmp = next;
	}
	*list = sorted;
}

/**
 * sorted_insertion - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The linked list
 * @tmp: The node to insert
 * Return: Nothing
 */
void sorted_insertion(listint_t **list, listint_t *tmp)
{
	listint_t *tmp2;

	if (*list == NULL)
		*list = tmp;

	else if ((*list)->n >= tmp->n)
	{
		tmp->next = *list;
		tmp->next->prev = tmp;
		*list = tmp;
	}

	else
	{
		tmp2 = *list;
		while (tmp2->next != NULL && tmp2->next->n < tmp->n)
			tmp2 = tmp2->next;

		if (tmp2->next != NULL)
			tmp->next->prev = tmp;

		tmp2->next = tmp;
		tmp->prev = tmp2;
	}
}
