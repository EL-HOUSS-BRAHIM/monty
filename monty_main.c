#include "monty.h"

void push(Stack *stack, int value, int line_number) {
    if (stack->top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->stack[stack->top] = value;
}

int pop(Stack *stack, int line_number) {
    if (stack->top == -1) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    return stack->stack[stack->top--];
}

void pall(Stack *stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->stack[i]);
    }
}

void pint(Stack *stack, int line_number) {
    if (stack->top == -1) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack->stack[stack->top]);
}

void swap(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top - 1];
    stack->stack[stack->top - 1] = temp;
}

void add(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->stack[stack->top - 1] += stack->stack[stack->top];
    stack->top--;
}

void nop() {
    // Do nothing
}
