#include "monty.h"

/* Function to push a value onto the stack */
void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    top++;
    stack[top] = value;
}

/* Function to print all values on the stack */
void pall(void) {
    int i;

    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

/* Function to print the value at the top of the stack */
void pint(void) {
    if (top == -1) {
        fprintf(stderr, "Error: L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack[top]);
}

/* Function to remove the top element of the stack */
void pop(void) {
    if (top == -1) {
        fprintf(stderr, "Error: L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    top--;
}

/* Function to swap the top two elements of the stack */
void swap(void) {
    if (top < 1) {
        fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}

/* Function to add the top two elements of the stack */
void add(void) {
    if (top < 1) {
        fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack[top - 1] += stack[top];
    pop();  /* Remove the top element*/
}

/* Function for the nop opcode (does nothing) */
void nop(void) {
    /* Do nothing*/
}
