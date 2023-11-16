#include "monty.h"

void pint(void) {
    if (top == -1) {
        fprintf(stderr, "Error: L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack[top]);
}
