#include "monty.h"

/**
 * _push - function that adds a new value to the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: number of the line of execution.
 *
 * Return: void.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *node = NULL;
	char *token = NULL;
	int n = 0;

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \n\t\r");
	if (token == NULL || _isnumber(token) == 0)
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new->n = n;
	new->next = NULL;
	node = *stack;
	if (node == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (node->next != NULL)
		node = node->next;
	new->prev = node;
	node->next = new;
}
