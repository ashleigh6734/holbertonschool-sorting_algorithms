#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        while (temp->prev && temp->n < temp->prev->n)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            temp->next->prev = temp;
            print_list(*list);
        }
        current = current->next;
    }
}
