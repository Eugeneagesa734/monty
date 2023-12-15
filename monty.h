#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - A stack (or queue) represented by a doubly linked list
 * @n: integer
 * @prev: refers to the stack's (or queue's) preceding element
 * @next: indicates the position of the next stack (or queue) element
 *
 * Description: doubly linked list node structure for FIFO, LIFO, stack and queue
 */
typedef struct instruction_s 
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file_name);
void read_file(FILE *);
int parse_line(char *buffer, int line_number, int format);
int len_chars(FILE *);
void find_func(char *, char *, int, int);


stack_t *create_node(int n);
void free_nodes(void);
void add_to_stack(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void nop(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void swap_nodes(stack_t **, usigned int);

void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

void print_char(stack_t **, unsigned int);
void rot1(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);

void err(int error_code, ...);
void rotr(stack_t **, unsined int);

#endif
