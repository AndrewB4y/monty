#include "monty.h"


/**
 * _mod - computes the rest of the division of the second by the first
 *        element of the stack.
 * @stack: head of the stack.
 * @line_number: line number in the code where this function was called.
 *
 * Return: void.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int res = 0;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (node != NULL)
			free(node);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		close(fd);
		exit(EXIT_FAILURE);
	}
	res = node->next->n % node->n;
	_pop(stack, line_number);
	(*stack)->n = res;
}
