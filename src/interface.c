#include <stdio.h>
#include <stdlib.h>

/*
 * Simple UI for Part A: print a prompt and echo input back to the user.
 *
 * Usage:
 *   ./tokenizer_ui
 *
 * Type lines and they will be echoed. End the program with EOF (Ctrl-D)
 * or by entering the command "exit" on its own line.
 */

int main(void) {
    char buffer[1024];

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
