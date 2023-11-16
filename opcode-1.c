#include "monty.h"
/**
 * push - Pushes a value onto the stack
 * @monty: Monty struct representing the stack
 * @value: Value to be pushed onto the stack
 * @line_number: Line number in the Monty bytecode file
 */
void push(Monty *monty, int value, int line_number)
{
if (monty->stack_size >= STACK_SIZE)
{
fprintf(stderr, "L%d: stack overflow\n", line_number);
exit(EXIT_FAILURE);
}
monty->stack[monty->stack_size++] = value;
}
/**
 * pall - Prints all values on the stack
 * @monty: Monty struct representing the stack
 */
void pall(Monty *monty)
{
int i;
for (i = monty->stack_size - 1; i >= 0; i--)
{
printf("%d\n", monty->stack[i]);
}
}
/**
 * pint - Prints the value at the top of the stack
 * @monty: Monty struct representing the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pint(Monty *monty, int line_number)
{
if (monty->stack_size == 0)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", monty->stack[monty->stack_size - 1]);
}
/**
 * pop - Removes the top element from the stack
 * @monty: Monty struct representing the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pop(Monty *monty, int line_number)
{
if (monty->stack_size == 0)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
monty->stack_size--;
}
