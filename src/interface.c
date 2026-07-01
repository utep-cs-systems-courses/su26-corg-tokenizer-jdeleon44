#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[100];

    while (1) {
        /* prompt */
        fputs("$ ", stdout);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            /* EOF or read error */
            break;
        }

        /* If user typed "exit\n" terminate */
        if (strcmp(buffer, "exit\n") == 0 || strcmp(buffer, "exit") == 0) {
            break;
        }

        /* Echo the input back to the user. fgets keeps the trailing newline. */
        fputs(buffer, stdout);
    }

    return 0;
}
