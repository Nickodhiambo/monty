#include "monty.h"

/**
 * main - Entry point to intepreter
 * @ac: Argument count
 * av: Arugument vector
 * Return 0(Success)
 */

int main(int ac, char **av __attribute__((unused)))
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
