#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void factorize(int num) {
    int i;
    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            printf("%d=%d*%d\n", num, i, num / i);
            return;
        }
    }
    printf("%d=%d*%d\n", num, 1, num);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    signal(SIGALRM, SIG_IGN); // Ignore alarm in case the file processing exceeds 5 seconds

    alarm(5); // Set an alarm for 5 seconds

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
