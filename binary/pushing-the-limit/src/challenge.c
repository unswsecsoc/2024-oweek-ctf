#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[64];
    unsigned char age;
};

int main(void) {
    struct person person;

    printf("how old are you? ");
    scanf("%hhu", &person.age);

    if (person.age < 0 || person.age > 99) {
        printf("err: invalid age (expected between 0 and 99, got %hhu)\n", person.age);
        exit(EXIT_FAILURE);
    }

    printf("what's your name? ");
    scanf("%s", person.name);

    if (person.age == 100) {
        FILE *f = fopen("flag.txt", "rb");
        int c;

        printf("happy centenary %s!\n", person.name);
        printf("here's a gift to celebrate 100 years: ");

        while ((c = fgetc(f)) != EOF) {
            fputc(c, stdout);
        }

        fclose(f);
    }

    else {
        printf("you aren't old enough at %hhu to receive the prize, %s\n", person.age, person.name);
    }

    return 0;
}
