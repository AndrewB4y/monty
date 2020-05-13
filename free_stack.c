#include "monty.h"

/**
 * free_stack - function that frees a stack_t stack.
 * @head: pointer to the head of the stack.
 *
 * Return: void.
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
