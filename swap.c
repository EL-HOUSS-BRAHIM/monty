#include "monty.h"

void swap(void) {
    int temp;
    if (top < 1) {
        fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}
