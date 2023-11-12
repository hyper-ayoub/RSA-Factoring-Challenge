#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/*
 * Main function: Entry point of the program
 *
 * This function reads a file specified in the command-line argument and
 * calculates and prints the prime factors of the numbers found in the file.
 *
 * Parameters:
 * @ argc: Number of command-line arguments
 * @ argv: Array of command-line argument strings
 *
 * Returns:
 *  - EXIT_SUCCESS if the program executes successfully
 *  - EXIT_FAILURE if there is an error
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	long long flag = 1, div, rest, number, counter;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		flag = 1, div = 2;
		number = atoll(line);
		while (flag)
		{
			rest = number % div;
			if (!rest)
			{
				counter = number / div;
				printf("%lld=%lld*%lld\n", number, counter, div);
				flag = 0;
			}
			div++;
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

