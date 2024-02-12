// Credits to abiram for the original challenge idea and structure.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

int main(void) {
    printf("Meowdy! Congratulations on successfully connecting!\n");
    printf("To get the flag, type \"meow\" back at me, and press the Enter key so I can hear what you've said.\n");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (true) {
        printf(">> ");

        if (getline(&line, &len, stdin) == -1) {
            printf("getline: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "meow") == 0) {
            break;
        }

        printf("That doesn't sound like a meow. Try again :)\n");
    }

    printf("Hey ma! I'm a cool cybercat with a flag now! OWEEK{purr_n3t_cat5_ar3_c0ol}\n");
    free(line);
    return 0;
}
