#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom.
 * @head: The stack head.
 * @count: The line number.
 * Return: No return value.
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
stack_t *copy;

copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}
/**
 * print_stack - Prints to the top.
 * @head: The stack head.
 * @count: The line number.
 * Return: No return value.
 */
void print_stack(stack_t **head, unsigned int count)
{
(void)head;
(void)count;
bus.lifi = 0;
}
/**
 * sub - Subtraction.
 * @head: The stack head.
 * @count: The line number.
 * Return: No return value.
 */
void sub(stack_t **head, unsigned int count)
{
stack_t *aux;
int sus, nodes;

aux = *head;
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", count);
fclose(bus.file);
free(bus.cont);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
sus = aux->next->n - aux->n;
aux->next->n = sus;
*head = aux->next;
free(aux);
}
/**
 * swap - Swaps the top two elements of the stack.
 * @head: The stack head.
 * @count: The line number.
 * Return: No return value.
 */
void swap(stack_t **head, unsigned int count)
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
fprintf(stderr, "L%d: can't swap, stack too short\n", count);
fclose(bus.file);
free(bus.cont);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->n;
h->n = h->next->n;
h->next->n = aux;
}