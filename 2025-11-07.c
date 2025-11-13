#include <stdio.h>
#include <math.h>

float inverse_square_root(float number) {
    return 1.0/sqrt(number);
}

float fast_inverse_sqrt(float number) {
    float x1;
    

    float result = x1 * (1.5 - 0.5*x1*x1*number);
}

// void popcount(unsigned int x)
// numaram bitii egali cu 1 din x
int popcount(unsigned int x) {
    int suma = 0;
    while (x) {
        suma += x&1;
        x >>= 1;
    }
    return suma;
}

// void ctz(unsigned int x)
// count trailing zeros

// void hamming_distance(unsigned int x, unsigned int y)
// nr de biti diferiti e.g hamming(5,3) == 2

void afiseaza_binar(unsigned int x) {
    for (int i=sizeof(x)*8-1; i>=0; i--) {
        int b = (x>>i)&1;
        printf("%d", b);
        if (i%8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    unsigned int x=5;
    unsigned int y=3;

    // x += 5; // echivalent cu x = x+5;
    // x >>= 1; // echivalent cu x = x >> 1;

    // printf("%u\n", x>>y);
    afiseaza_binar(x);
    afiseaza_binar(y);

    printf("%d\n", popcount(5));
    printf("%d\n", popcount(64));
    printf("%d\n", popcount((1<<8)-1));

    int n;
    unsigned int multime = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int a; 
        scanf("%d", &a);
        multime |= (1<<a);
    }

}