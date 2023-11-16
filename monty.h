#pragma once

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024

extern int stack[STACK_SIZE];
extern int top;
extern int line_number;

void push(int value);
void pall(void);
void pint(void);
void pop(void);
void swap(void);
void add(void);
void nop(void);
