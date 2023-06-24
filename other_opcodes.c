#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack
 * @stack: The stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}


/**
 * pstr - Prints the string starting at the top of the stack
 * followed by a new line
 * @stack: stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp != NULL && temp->n != 0 && temp->n >= 0 &&
	       temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}


/**
 * rotl - Rotates the stack to the top
 * @stack: The stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *second, *last;

	(void) line_number;

	if (top != NULL && top->next != NULL)
	{
		second = top->next;
		last = top;

		while (last->next != NULL)
			last = last->next;

		*stack = second;
		second->prev = NULL;
		last->next = top;
		top->prev = last;
		top->next = NULL;
	}
}


/**
 * rotr - Rotates the stack to the bottom
 * @stack: The stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void) line_number;

	if (last != NULL && last->next != NULL)
	{
		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
