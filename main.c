#define _GNU_SOURCE
#include "monty.h"

/**
 *main - Entry point for the Monty interpreter
 *@argc: Number of command-line arguments
 *@argv: Array of command-line arguments
 *Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	(void)stack;  /* Suppress unused variable warning */


	if (argc != 2)
	{
		fprintf(stderr, "Error: Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		/*Process each line of Monty bytecode here */
		/*You'll need to parse the line and execute the corresponding command */
		parse_and_execute(&stack, line, line_number);
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
