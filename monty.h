#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>

/**
 *struct stack_s - Doubly linked list representation of a stack (or queue)
 *@n: Integer
 *@prev: Points to the previous element of the stack (or queue)
 *@next: Points to the next element of the stack (or queue)
 *
 *Description: Doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 *Function prototypes
 */
void push(stack_t **stack, unsigned int line_number, int n);
void pall(stack_t **stack, unsigned int line_number);


#endif /*MONTY_H */
