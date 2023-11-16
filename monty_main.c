#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Stack stack;
    stack.top = -1;

    char opcode[100];
    int value, line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF) {
        line_number++;
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&stack, line_number);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&stack, line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&stack, line_number);
        } else if (strcmp(opcode, "add") == 0) {
            add(&stack, line_number);
        } else if (strcmp(opcode, "nop") == 0) {
            nop();
        } else {
            fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    return 0;
}
