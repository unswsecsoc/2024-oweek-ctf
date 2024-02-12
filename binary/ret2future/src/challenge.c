#include <stdio.h>

typedef void (function)(void);

struct data {
    char name[64];
    function* function;
};

void win() {
    FILE *f = fopen("flag.txt", "rb");
    int c;

    while ((c = fgetc(f)) != EOF) {
        fputc(c, stdout);
    }

    fclose(f);
}

void lose() {
    printf("this isn't where you want to be\n");
}

int main(void) {
    printf("psst... i'll give you a hint, you can get the flag if you go to %p\n", win);

    struct data data;
    data.function = lose;
    printf("what's your name? ");
    scanf("%s", data.name);

    printf("ok %s, today i've decided you're going to %p\n", data.name, data.function);
    data.function();
    return 0;
}
