#include <stdio.h>
#include <string.h>

// int f(struct student x) { 
// }

int main() {
    union int_bytes {
        int x;
        unsigned char v[4];
    };

    struct student {
        char nume[20];
        int nota;
    };

    int x = 0;

    unsigned char *c;
    c = (unsigned char*)&x;
    *c = 192;
    c++;
    *c = 168;
    c++;
    *c = 43;
    c++;
    *c = 241;

    printf("%d\n", x);

    // cu iterare cu unsigned char *
    for (unsigned char *p=(unsigned char *)&x; p < (unsigned char *)(&x+1); p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // type pun cu memcpy
    unsigned char v[4];
    memcpy(v, &x, 4);
    for (int i=0; i<4; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // type pun cu union
    union int_bytes my_union;
    my_union.x = x;
    for (int i=0; i<4; i++) {
        printf("%d ", my_union.v[i]);
    }
    printf("\n");
}