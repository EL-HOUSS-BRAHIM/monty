#include "monty.h"

void add(void) {
    if (top < 1) {
        fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack[top - 1] += stack[top];
    pop();  // Remove the top element
}
