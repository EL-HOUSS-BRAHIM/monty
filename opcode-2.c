#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack
 * @monty: Monty struct representing the stack
 * @line_number: Line number in the Monty bytecode file
 */
void swap(Monty *monty, int line_number)
{
int temp;
if (monty->stack_size < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = monty->stack[monty->stack_size - 1];
monty->stack[monty->stack_size - 1] = monty->stack[monty->stack_size - 2];
monty->stack[monty->stack_size - 2] = temp;
}
/**
 * add - Adds the top two elements of the stack
 * @monty: Monty struct representing the stack
 * @line_number: Line number in the Monty bytecode file
 */
void add(Monty *monty, int line_number)
{
if (monty->stack_size < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
monty->stack[monty->stack_size - 2] += monty->stack[monty->stack_size - 1];
monty->stack_size--;
}
/**
 * nop - Does nothing
 */
void nop(void)
{
/* Do nothing*/
}
