#include "monty.h"

/**
 * check_f - function that checks if a string is part of the available
 *              functions for the interpretation of a Monty 0.98 code.
 * @tkn: input string to be checked.
 * @s: indicator for mode stack o queue, 1 for stack, 0 for queue.
 * @stack: head of the stack.
 * @count: line number in code.
 *
 * Return: pointer to the callable function, NULL if not found.
 */

opcode_p check_f(char *tkn, int *s, stack_t *stack, unsigned int count)
{
	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{NULL, NULL}
	};
	opcode_p f = NULL;
	int i = 0;

	f = check_stk_queue(tkn, s);
	if (f != NULL)
		return (f);
	while (funcs[i].opcode != NULL && _strcmp(tkn, funcs[i].opcode))
		i++;
	if (funcs[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, tkn);
		free_stack(stack);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (funcs[i].f == _push && s == 0)
		return (_q_push);
	return (funcs[i].f);
}

/**
 * check_stk_queue - function that checks if a token indicate to reverse
 *                   for stack mode, o queue mode.
 * @tkn: input string or token to be checked.
 * @s: indicator for mode stack o queue, 1 for stack, 0 for queue.
 *
 * Return: pointer to the callable function, NULL if not found.
 */

opcode_p check_stk_queue(char *tkn, int *s)
{
	if (_strcmp(tkn, "stack") == 0 && *s == 0)
	{
		*s = 1;
		return (_reverse);
	}
	else if (_strcmp(tkn, "queue") == 0 && *s == 1)
	{
		*s = 0;
		return (_reverse);
	}
	else if (_strcmp(tkn, "stack") == 0 || _strcmp(tkn, "stack") == 0)
	{
		return (_nop);
	}
	return (NULL);
}
