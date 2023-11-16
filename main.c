#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/**
 * struct Stack - Stack structure
 * @data: Array to store stack elements
 * @top: Index of the top element in the stack
 */
typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

Stack stack;

/**
 * push - Pushes an element to the stack
 * @value: Integer value to be pushed onto the stack
 * @line_number: Line number in the file where the push operation is called
 */
void push(int value, int line_number) {
    if (stack.top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.data[++stack.top] = value;
}

/**
 * pall - Prints all the values on the stack
 * @line_number: Line number in the file where the pall operation is called
 */
void pall(int line_number) {
    int i;
    for (i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.data[i]);
    }
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;
        if (line[0] != '\n' && line[0] != '#') {
            char opcode[5];
            int value;
            if (sscanf(line, "%4s %d", opcode, &value) == 2) {
                if (strcmp(opcode, "push") == 0) {
                    push(value, line_number);
                } else if (strcmp(opcode, "pall") == 0) {
                    pall(line_number);
                } else {
                    fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
                    exit(EXIT_FAILURE);
                }
            } else {
                fprintf(stderr, "L%d: invalid instruction\n", line_number);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    if (line) {
        free(line);
    }

    return 0;
}
