#include "monty.h"

arg_t *arguments = NULL;
/**
 * initialize_arguments - initialize a pointer to
 * arg_s structure.
 */
void initialize_arguments()
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();
	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
	arguments->head = NULL;
	arguments->stack_length = 0;
	arguments->instruction = malloc(sizeof(instruction_t));
	if (!arguments->instruction)
		malloc_failed();
}
