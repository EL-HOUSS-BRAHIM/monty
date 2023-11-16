#include "monty.h"

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    top++;
    stack[top] = value;
}
