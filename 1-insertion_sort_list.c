#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list by insertion
 * @list: received list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nodecurrent, *nodeprev, *temp;

	if (!list)
		return;
	nodecurrent = *list;
	while ((nodecurrent = nodecurrent->next))
	{
		temp = nodecurrent;
		while (temp->prev && temp->prev->n > temp->n)
		{
			nodeprev = temp->prev;
			if (temp->next)
				temp->next->prev = nodeprev;
			if (nodeprev->prev)
				nodeprev->prev->next = temp;
			else
				*list = temp;
			nodeprev->next = temp->next;
			temp->prev = nodeprev->prev;
			temp->next = nodeprev;
			nodeprev->prev = temp;
			print_list(*list);
		}
	}
}
