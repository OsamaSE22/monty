#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

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
 * struct arg_s - hold variables
 * @stream: File that connects to the stream from file.
 * @line: string which will be the line of text read from stream.
 *
 * Description: hold variables that will be used.
 * in different functions of the project as well as variables
 * that will require memory allocation and freeing
 */
/* Forward declaration for instruction_t */
typedef struct instruction_s instruction_t;
typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head; /* pointer to the top of the stack  */
	unsigned int stack_length; /* number of elements in the stack  */
} arg_t;

extern arg_t *arguments;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
};
int is_number(char *str);
void close_stream(void);
void tokenize_line(void);
void getting_stream_failed(char *fileName);
void get_stream(char *fileName);
void free_arguments();
void validate_arguments(int argc);
void malloc_failed(void);
void initialize_arguments();
void invalid_instruction(void);
void get_instruction(void);
void run_instruction(void);
void free_tokens(void);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H  */

