#include "monty.h"
/**
 * mult_to_2 - Multiplies the top two elements of the stack.
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void mult_to_2(stack_t **head, unsigned int count)
{
stack_t *h;
int len = 0, aux;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->next->n * h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
/**
 * non - Does nothing.
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void non(stack_t **head, unsigned int count)
{
  (void) counter;
  (void) head;
}
/**
 * pall - Print the elements of the stack.
 * @head: A pointer to the stack's head.
 * @counter: Unused.
 * Return: No return value.
 */
void pall(stack_t **head, unsigned int count)
{
stack_t *h;
(void)counter;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
/**
 * pcfs - Prints the character at the top of the stack,
 * followed by a new line.
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void pcfs(stack_t **head, unsigned int count)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}
