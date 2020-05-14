#include "monty.h"

/**
 * read_monty - function that reads and interpretates a monty file.
 * @file: name of the monty file to be interpretated.
 *
 * Return: 0 on success, 1 on failure
 */

int read_monty(char *file)
{
	int fd = -1, stk = 1;
	char buf[1024], line[1024], *token = NULL;
	ssize_t ra = 0, bsize = sizeof(buf) / sizeof(buf[0]);

	int i = 0, start = 0, end = 0, stay1 = 1;
	int n_bytes = 0, count = 0, error = 0, stay2 = 1;

	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	if (file == NULL)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	while (stay1)
	{
		ra = read(fd, &buf[i], bsize - n_bytes);
		if (ra <= 0)
			return (1);
		if (ra < bsize)
		{
			bsize = ra;
			stay1 = 0;
		}
		while (stay2)
		{
			if (end + 1 < bsize && end != 0)
			{
				start = end + 1;
				end = start;
			}
			else if (end + 1 >= bsize)
			{
				n_bytes = 0;
				i = 0;
				stay2 = 0;
				continue;
			}
			while (end < bsize && buf[end] != '\n')
				end++;
			if (buf[end] != '\n')
			{
				--end;
				n_bytes = end - start + 1;
				for (i = 0; i < n_bytes; i++)
					buf[i] = buf[start + i];
				stay2 = 0;
				continue;
			}
			n_bytes = end - start + 1;
			++count;
			_strncpy(line, &buf[start], n_bytes);
			line[n_bytes] = '\0';
			token = strtok(line, " \n\t\r");
			if (token == NULL)
				continue;
			f = check_f(token, &stk);
			if (f == NULL)
			{
				fprintf(stderr, "L<%d>: unknown instruction <%s>", count, token);
				stay1 = 0;
				error = EXIT_FAILURE;
				break;
			}
			f(&stack, count);
		}
	}

	return (error);
}
