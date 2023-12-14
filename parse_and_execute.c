#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 *parse_and_execute - Parses and executes Monty bytecode commands
 *@stack: Double pointer to the head of the stack
 *@line: Line from the Monty bytecode file
 *@line_number: Line number in the Monty bytecode file
 */
void parse_and_execute(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;
	int value;

	opcode = strtok(line, " \t\n");
	if (!opcode)
		return;

	if (strcmp(opcode, "push") == 0)
	{
		/* Parse the integer value */
		char *arg = strtok(NULL, " \t\n");

		if (!arg)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		value = atoi(arg);
		push(stack, line_number, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}

	/* Add more cases for other opcodes as needed */
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
