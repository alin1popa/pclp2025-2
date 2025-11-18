#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *nume;
    int an;
    float nota;
};

void f(struct student s) {
    s.nume[0]='X';
}

int main() {
    struct student gigel;
    gigel.an = 2;
    gigel.nota = 8.5;
    gigel.nume = malloc(20);
    strcpy(gigel.nume, "Gigel");

    printf("Studentul este %s, anul %d, nota %f\n", gigel.nume, gigel.an, gigel.nota);
    f(gigel);
    printf("Studentul este %s, anul %d, nota %f\n", gigel.nume, gigel.an, gigel.nota);
}