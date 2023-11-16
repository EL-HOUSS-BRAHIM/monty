#include "monty.h"
/**
 * open_file - Opens a Monty bytecode file for reading
 * @filename: Name of the file to open
 * Return: File pointer if successful, NULL otherwise
 */
FILE *open_file(char *filename)
{
FILE *file = fopen(filename, "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
return (file);
}
/**
 * process_inst - Processes a single Monty instruction
 * @monty: Monty struct representing the stack
 * @opcode: Current opcode to process
 * @value: Value associated with the opcode (if applicable)
 * @line_number: Current line number in the Monty bytecode file
 */
void process_inst(Monty *monty, char *opcode, int value, int line_number)
{
if (strcmp(opcode, "push") == 0)
{
push(monty, value, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(monty);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(monty, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(monty, line_number);
}
else if (strcmp(opcode, "swap") == 0)
{
swap(monty, line_number);
}
else if (strcmp(opcode, "add") == 0)
{
add(monty, line_number);
}
else if (strcmp(opcode, "nop") == 0)
{
nop();
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */
int main(int argc, char *argv[])
{
FILE *file;
Monty monty;
char opcode[256];
int value, line_number = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: %s <file>\n", argv[0]);
exit(EXIT_FAILURE);
}
file = open_file(argv[1]);
monty.stack_size = 0;
while (fscanf(file, "%s", opcode) != EOF)
{
line_number++;
if (strcmp(opcode, "push") == 0)
{
if (fscanf(file, "%d", &value) == 1)
{
process_inst(&monty, opcode, value, line_number);
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
else
{
process_inst(&monty, opcode, 0, line_number);
}
}
fclose(file);
return (EXIT_SUCCESS);
}
