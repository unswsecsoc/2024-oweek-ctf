#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("flag.txt", "rb");

    int i = 0;
    printf("enter no. of bytes to read: ");
    scanf("%d", &i);
    printf("attempting to read %d bytes\n", i);

    if (i > 5) {
        printf("err: can only read up to 5 bytes\n");
        exit(EXIT_FAILURE);
    }

    int c = fgetc(f);

    while (c != EOF && --i + 1 > 0) {
        fputc(c, stdout);
        c = fgetc(f);
    }

    fclose(f);
    return 0;
}
