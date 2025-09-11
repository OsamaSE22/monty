#include "monty.h"
/**
 * get_instruction - Sets the instruction based on the first token
 * in the input line.
 */
void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop},   {"add", &add},
		{"pall", &pall}, {"sub", &sub},
		{"div", &_div},  {"mul", &mul},
		{"rotl", &rotl}, {"rotr", &rotr},
		{"stack", &stack}, {"queue", &queue},
		{"pstr", &pstr}, {"pchar", &pchar},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0) /* no instructions */
		return;
	for(; instructions[i].opcode != NULL; i++)
	{
		/* compare opcode of instruction to first token (instruct..)  */
		if (strcmp(instructions[i].opcode, arguments->tokens[0]) == 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_instruction();
}
