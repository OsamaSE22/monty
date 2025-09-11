#include "monty.h"

/**
 * invalid_instruction - Handles an unknown instruction error.
 */
void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", arguments->line_number, arguments->tokens[0]);
	close_stream();
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}
