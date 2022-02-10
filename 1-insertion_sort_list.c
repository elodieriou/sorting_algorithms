#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list;
	listint_t *left = NULL;
	listint_t *right = NULL;

    if (*list == NULL || (*list)->next == NULL)
        return;

    tmp = (*list)->next;
	while (tmp != NULL)
	{
        left = tmp->prev;
        right = tmp->next;
        while (tmp->n < left->n)
        {
            if (left->prev != NULL)
                left->prev->next = tmp;
            left->next = tmp->next;
            tmp->next = left;
            left->prev = tmp;
            tmp->prev = left->prev;
            if (right != NULL)
                right->prev = left;
            print_list(*list);
            right = tmp->next;
            left = tmp->prev;
        }
        tmp = right;
	}
}
