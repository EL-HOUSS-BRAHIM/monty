#include "monty.h"
/**
 * push - Add node to the stack.
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void push(stack_t **head, unsigned int count)
{
int n, j = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > 57 || bus.arg[j] < 48)
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
n = atoi(bus.arg);
if (bus.lifi == 0)
add_node(head, n);
else
addToQueue(head, n);
}
/**
 * setQueueMode - Sets the stack to queue mode (FIFO).
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void setQueueMode(stack_t **head, unsigned int count)
{
(void)head;
(void)counter;
bus.lifi = 1;
}
/**
 * addToQueue - Adds a new node to the tail of the queue.
 * @n: The new value to be added to the queue.
 * @head: A pointer to be added to the queue.
 * Return: No return value.
 */
void addToQueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (aux)
{
while (aux->next)
aux = aux->next;
}
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}
/**
 * rotatestack - Rotates the stack to the top.
 * @head: The stack head.
 * @counter: The line number.
 * Return: No return value.
 */
void rotatestack(stack_t **head, __attribute__((unused)) unsigned int count)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}
