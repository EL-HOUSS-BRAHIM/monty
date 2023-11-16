#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value, int line_number);
int pop(Stack *stack, int line_number);
void pall(Stack *stack);
void pint(Stack *stack, int line_number);
void swap(Stack *stack, int line_number);
void add(Stack *stack, int line_number);
void nop();

#endif /* MONTY_H */
