#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: head of the stack.
 * @line_number: line number in the code where this function was called.
 *
 * Return: void.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int res = 0;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (node != NULL)
			free(node);
		close(fd);
		exit(EXIT_FAILURE);
	}
	res = node->n + node->next->n;
	_pop(stack, line_number);
	(*stack)->n = res;
}
