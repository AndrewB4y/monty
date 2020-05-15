#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack.
 * @stack: head of the stack.
 * @line_number: line number in the code where this function was called.
 *
 * Return: void.
 */

void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *nd = *stack;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (nd != NULL && nd->n != 0 && nd->n >= 0 && nd->n <= 127)
	{
		printf("%c", nd->n);
		nd = nd->next;
	}
}
