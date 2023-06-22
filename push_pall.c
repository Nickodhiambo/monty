#include "monty.h"

/**
 * push - Inserts an element to a stack
 * @stack: The stack_t structure
 * @line_number: unsigned integer representating number
 * of lines in a monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	int value;
	size_t i;
	stack_t *new_node;

	if (!value_str)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; value_str[i] != '\0'; i++)
	{
		if (value_str[i] == '-' && i == 0)
			continue;
		if (value_str[i] < '0' || value_str[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(value_str);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
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
		temp = temp->next;
	}

}
