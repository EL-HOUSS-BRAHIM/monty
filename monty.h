#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line cont
 * @arg: value
 * @file: pointer to monty file
 * @cont: line cont
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *realloc_(char *ptr, unsigned int old, unsigned int new);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *cont);
void push(stack_t **head, unsigned int num);
void pall(stack_t **head, unsigned int num);
void pte(stack_t **head, unsigned int num);
int exec(char *cont, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void custom_print (stack_t **head, unsigned int count);
void swap(stack_t **head, unsigned int count);
void atte(stack_t **head, unsigned int count);
void non(stack_t **head, unsigned int count);
void sub(stack_t **head, unsigned int count);
void ants(stack_t **head, unsigned int count);
void mult_to_2(stack_t **head, unsigned int count);
void mod_top_2(stack_t **head, unsigned int count);
void pcfs(stack_t **head, unsigned int count);
void pc(stack_t **head, unsigned int count);
void rotatestack(stack_t **head, unsigned int count);
void rotr(stack_t **head, __attribute__((unused)) unsigned int count);
void add_node(stack_t **head, int n);
void addToQueue(stack_t **head, int n);
void setQueueMode(stack_t **head, unsigned int count);
void print_stack(stack_t **head, unsigned int count);