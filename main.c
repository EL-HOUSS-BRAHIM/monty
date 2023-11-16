#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char opcode[100];  /* Adjust the size as needed*/
    int value;

    while (fscanf(file, "%99s", opcode) == 1) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else if (strcmp(opcode, "pint") == 0) {
            pint();
        } else if (strcmp(opcode, "pop") == 0) {
            pop();
        } else if (strcmp(opcode, "swap") == 0) {
            swap();
        } else if (strcmp(opcode, "add") == 0) {
            add();
        } else if (strcmp(opcode, "nop") == 0) {
            nop();
        } else {
            fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        /* Increment line_number as each opcode is processed*/
        line_number++;
    }

    fclose(file);
    return 0;
}
