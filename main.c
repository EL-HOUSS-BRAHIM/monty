#include "monty.h"
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */
int main(int argc, char *argv[]) {
FILE *file;
Monty monty;
char opcode[256];
int value, line_number = 0;
if (argc != 2) {
fprintf(stderr, "USAGE: %s <file>\n", argv[0]);
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL) {
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
monty.stack_size = 0;
while (fscanf(file, "%s", opcode) != EOF) {
line_number++;
if (strcmp(opcode, "push") == 0) {
if (fscanf(file, "%d", &value) == 1) {
push(&monty, value, line_number);
} else {
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
} else if (strcmp(opcode, "pall") == 0) {
pall(&monty);
} else if (strcmp(opcode, "pint") == 0) {
pint(&monty, line_number);
} else if (strcmp(opcode, "pop") == 0) {
pop(&monty, line_number);
} else if (strcmp(opcode, "swap") == 0) {
swap(&monty, line_number);
} else if (strcmp(opcode, "add") == 0) {
add(&monty, line_number);
} else if (strcmp(opcode, "nop") == 0) {
nop();
} else {
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
fclose(file);
return 0;
}
