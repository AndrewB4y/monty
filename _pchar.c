#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack.
 * @stack: pointer to the head of the stack.
 * @line_number: line in monty code of where this function was called
 *
 * Return: void.
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d : can't pchar, stack empty\n", line_number);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		fprintf(stderr, "L%d : can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
