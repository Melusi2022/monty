#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	ssize_t read_line;

	if (argc != 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, sizeof(content), file) != NULL)
	{
		counter++;
		read_line = strlen(content);
		if (read_line > 0)
		{
			if (content[read_line - 1] == '\n')
			{
				content[read_line - 1] = '\0';
			}
			execute(content, &stack, counter, file);
		}
	}
	fclose(file);
	free_stack(stack);
	return (0);
}	
