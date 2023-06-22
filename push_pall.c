#include "monty.h"

/**
 * push - Inserts an element to a stack
 * @stack: The stack_t structure
 * @line_number: unsigned integer representating number
 * of lines in a monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \t\n");
	int value;
	stack_t *newnode = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(argument[0]) && argument[0] != '-' && argument[0] != '+')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	newnode->n = value;
	newnode->prev = NULL;

	if (*stack != NULL)
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
	}
	newnode->next = NULL;

	*stack = newnode;
}


/**
 * pall - Prints all the values on a stack, starting from the top
 * @stack: A stack_t structure
 * @line_number: unsigned integer representing line count
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}

}
