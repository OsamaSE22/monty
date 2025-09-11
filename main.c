#include "monty.h"

/**
 * main - Entry point
 * @argc: the number of command line arguments.
 * @argv: A pointer to an array of strings containing the command-line arguments
 * Description: print alphabets in lowercase using putchar.
 *
 * Return: return 0. (success)
 */
int main(int argc, char* argv[])
{
	size_t n = 0;
	
	validate_arguments(argc);
	initialize_arguments();
	get_stream(argv[1]);

	while ((getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_number += 1; /* tracking the line number of the file  */
		tokenize_line(); /*breaking line into words*/
		get_instruction(); /*run the funciton associated with opcode*/
		run_instruction();
		free_tokens(); /* free up memory for the tokens  */
		/*printf("%s", arguments->line);*/
	}
	close_stream(); /* close stream  */
	free_arguments(); /* free up memory allocated for the arguments pointer  */
	return (0);
}
