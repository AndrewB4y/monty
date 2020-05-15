#include "monty.h"

/**
 * free_stack - function that frees a stack_t stack.
 * @head: pointer to the head of the stack.
 *
 * Return: void.
 */

void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head->next;
		free(head);
		head = node;
	}
}
