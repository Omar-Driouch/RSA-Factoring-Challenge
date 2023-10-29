#include "factor.h"

/**
 * main - main function
 *
 *
 * Return: void
 */
 int main(int argc, char *argv[]) {
    FILE *fptr;
    size_t count = 0;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: factor <filename>\n");
        exit(EXIT_FAILURE);
    }

    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((line = getline(&buffer, &count, fptr)) != -1) {
        int inputValue = atoi(buffer);
         findPrimeFactors(inputValue);
     
    }

    // Free the allocated memory for buffer
    free(buffer);
    buffer = NULL;

    return 0;
}
