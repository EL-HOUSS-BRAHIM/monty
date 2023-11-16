#include "monty.h"

void swap(void) {
    if (top < 1) {
        fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}
