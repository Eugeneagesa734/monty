#include "monty.h"


/**
 * add_to_stack - A node is added to the stack.
 * @new_node: New node pointer.
 * @ln: An integer that indicates the opcode's line number.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - incorporates a node into the stack
 * @stack: pointer to a pointer that points to the stack's top node.
 * @line_number: The opcode line number.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - a node is added to the stack.
 * @stack: pointer to a pointer that points to the stack's top node.
 * @line_number: Line number of the opcode represented as an integer.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - the tallest node in the stack is printed.
 * @stack: pointer to a pointer that points to the stack's top node.
 * @line_number: An integer that indicates the opcode's line number.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
