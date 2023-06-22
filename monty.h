#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

/**
 * struct data_s - Contains file lines and their count
 * @lines:Lines of text in a file
 * @count:  number of lines in the file
 *
 * Description: Stores the content of a file
 */
typedef struct data_s
{
	char **lines;
	int count;
} data_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** functions in handle_files.c file */

void free_data_t(data_t file_contents);
data_t read_monty_file(const char *file_name);

/** function in execute_instructions.c file */
void find_instruction(char *opcode, stack_t **stack,
		      unsigned int line_number, char *argument);
void execute_instructions(data_t file_contents);

/** function in push_pall.c */
void push(stack_t **stack, unsigned int line_number, char *argument);
void pall(stack_t **stack, unsigned int line_number, char *argument);


#endif
