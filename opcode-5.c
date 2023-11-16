#include "monty.h"
/**
 * exec - Executes the specified opcode
 * @stack: A pointer to the head of the linked list (stack).
 * @count: The line_count
 * @file: Pointer to monty file
 * @cont: The line cont
 * Return: No return value
 */
int exec(char *cont, stack_t **stack, unsigned int count, FILE *file)
{
instruction_t opst[] = {
{"push", push}, {"pall", pall}, {"pint", pte}, {"pop", custom_print},
{"swap", swap}, {"add", atte},
{"nop", non}, {"sub", sub},
{"div", ants},
{"mul", mult_to_2}, {"mod", mod_top_2},
{"pchar", pcfs}, {"pstr", pc},
{"rotl", rotatestack}, {"rotr", rotr},
{"queue", setQueueMode}, {"stack", print_stack},
{NULL, NULL}
};
unsigned int i = 0;
char *op;
op = strtok(cont, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, count);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
fclose(file);
free(cont);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
/**
 * pte - Prints the top element of the stack.
 * @head: A pointer to the stack's head.
 * @count: The line number.
 * Return: No return value.
 */
void pte(stack_t **head, unsigned int count)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", count);
fclose(bus.file);
free(bus.cont);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
/**
 * custom_print - Prints the top element of the stack.
 * @head: A pointer to the stack's head.
 * @count: The line number.
 * Return: No return value.
 */
void custom_print(stack_t **head, unsigned int count)
{
stack_t *h;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", count);
fclose(bus.file);
free(bus.cont);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
*head = h->next;
free(h);
}
/**
 * pc - Prints the string starting at the top of the stack
 * followed by a new line.
 * @head: A pointer to stack's head.
 * @count: The line number.
 * Return: No return value.
 */
void pc(stack_t **head, unsigned int count)
{
stack_t *h;
(void)count;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
