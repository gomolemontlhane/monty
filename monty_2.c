#include "monty.h"

/**
 *swap - Swaps the top two elements of the stack
 *@stack: Pointer to the head of the stack
 *@line_number: Line number in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 *add - Adds the top two elements of the stack
 *@stack: Pointer to the head of the stack
 *@line_number: Line number in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *nop - Does nothing
 *@stack: Pointer to the head of the stack
 *@line_number: Line number in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	/*Do nothing */
}
