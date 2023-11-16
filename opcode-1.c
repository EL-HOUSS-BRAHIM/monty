#include "monty.h"
/**
 * atte- Adds the top two elements of the stack.
 * @head: A Pointer to the stack head
 * @counter: The line number
 * Return: No return value
*/
void atte(stack_t **head, unsigned int count)
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
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
aux = h->n + h->next->n;
h->next->n = aux;
*head = h->next;
free(h);
}
/**
 * add_node - Adds a node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: New value for the node
 * Return: No return
 */
void add_node(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
exit(0);
}
if (aux)
aux->prev = new_node;
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}
/**
 * ants - Add a new node to the head of the stack
 * @head: Pointer to head of the stack
 * @counter: Value to be added to the new code
 * Return: No return value
 */
void ants(stack_t **head, unsigned int count)
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
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = h->next->n / h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
/**
 * mod_top_2 - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @head: A pointer to the stack's head.
 * @counter: The line number.
 * Return: No return value.
 */
void mod_top_2(stack_t **head, unsigned int count)
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
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = h->next->n % h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
