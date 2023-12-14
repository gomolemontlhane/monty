#include "monty.h"

/**
 *push - Pushes an element to the stack
 *@stack: Pointer to the head of the stack
 *@line_number: Line number in the Monty bytecode file
 *@n: Value to be pushed
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node;

	(void)line_number; /* Suppress unused parameter warning */

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 *pall - Prints all values on the stack
 *@stack: Pointer to the head of the stack
 *@line_number: Line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;	/* Avoid unused parameter warning */

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
