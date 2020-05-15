#include "monty.h"


/**
 * _rotl - function that rotates the stack to the top.
 *         top element of the stack becomes the last one.
 * @stack: pointer to the head of the stack.
 * @line_number: line in monty code of where this function was called
 *
 * Return: void.
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
		return;
	_pop(stack, line_number);
	push_at_end(stack, node);
}

/**
 * push_at_end - function that adds a new node at the end
 *                    of the stack.
 * @stack: double pointer to the head of the stack.
 * @node: new node to be stored.
 *
 * Return: void.
 */

void push_at_end(stack_t **stack, stack_t *node)
{
	stack_t *new = node, *node_a = NULL;

	if (stack == NULL)
		return;
	new->next = NULL;
	node_a = *stack;
	if (node_a == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (node_a->next != NULL)
		node_a = node_a->next;
	new->prev = node_a;
	node_a->next = new;
}
