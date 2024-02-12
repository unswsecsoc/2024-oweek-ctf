#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y;

    printf("enter a pair of numbers that multiply to equal zero: ");
    scanf("%d %d", &x, &y);

    if (x == 0 || y == 0) {
        printf("err: numbers cannot be zero\n");
        exit(EXIT_FAILURE);
    }

    int r = x * y;

    if (r == 0) {
        FILE *f = fopen("flag.txt", "rb");
        int c;

        while ((c = fgetc(f)) != EOF) {
            fputc(c, stdout);
        }

        fclose(f);
    }

    else {
        printf("%d * %d = %d\n", x, y, r);
    }

    return 0;
}
