#include "monty.h"

/**
 * check_f - function that checks if a string is part of the available
 *              functions for the interpretation of a Monty 0.98 code.
 * @tkn: input string to be checked.
 * @s: indicator for mode stack o queue, 1 for stack, 0 for queue.
 *
 * Return: pointer to the callable function, NULL if not found.
 */

void (*check_f(char *tkn, int *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t stk_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	instruction_t q_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	instruction_t *funcs = NULL;
	int i = 0;

	funcs = stk_funcs;
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
	if (*s == 0)
		funcs = q_funcs;

	while (funcs[i].opcode != NULL && _strcmp(tkn, funcs[i].opcode))
		i++;

	if (funcs[i].opcode == NULL)
		return (NULL);

	return (funcs[i].f);
}
