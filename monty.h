#ifndef MONTY_H
#define MONTY_H

#define MAX_OPCODES 100

#define MAX_LINE_LENGTH 102

#include <stdio.h>

typedef struct
{
	int value;
} opcode_data_t;

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
	void (*f)(stack_t **stack, unsigned int line_number, void *data);
} instruction_t;

extern instruction_t instructions[];


void push(stack_t **stack, unsigned int line_number, void *data);
void pall(stack_t **stack, unsigned int line_number, void *data);
void pint(stack_t **stack, unsigned int line_number, void *data);
void pop(stack_t **stack, unsigned int line_number, void *data);
void swap(stack_t **stack, unsigned int line_number, void *data);
void add(stack_t **stack, unsigned int line_number, void *data);
void nop(stack_t **stack, unsigned int line_number, void *data);
instruction_t *find_instruction(char *opcode);
void process_instructions(FILE *file);


#endif /* MONTY_H */
