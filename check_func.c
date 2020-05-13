#include "monty.h"

/**
 * check_func - function that checks if a string is part of the available
 *              functions for the interpretation of a Monty 0.98 code.
 * @token: input string to be checked.
 *
 * Return: pointer to the callable function, NULL if not found.
 */

void (*check_func(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode != NULL && _strcmp(token, funcs[i].opcode))
		i++;

	if (funcs[i].opcode == NULL)
		return (NULL);

	return (funcs[i].f);
}
