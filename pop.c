#include "monty.h"

void pop(void) {
    if (top == -1) {
        fprintf(stderr, "Error: L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    top--;
}
