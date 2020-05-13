#include "monty.h"

/**
 * _pint - function that prints the top of the stack.
 * @stack: pointer to the head of the stack.
 * @line_number: line in monty code of where this function was called
 *
 * Return: void.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h == NULL)
	{
		fprintf(stderr, "L<%d> : can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (h->next != NULL)
		h = h->next;

	printf("%d\n", h->n);
}
