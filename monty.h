#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 1000
/**
 * struct Monty - Stack structure for Monty interpreter
 * @stack: Array representing the stack
 * @stack_size: Current size of the stack
 */
typedef struct Monty {
    int stack[STACK_SIZE];
    int stack_size;
} Monty;

void push(Monty *monty, int value, int line_number);
void pall(Monty *monty);
void pint(Monty *monty, int line_number);
void pop(Monty *monty, int line_number);
void swap(Monty *monty, int line_number);
void add(Monty *monty, int line_number);
void nop(void);