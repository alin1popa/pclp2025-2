#include <stdio.h>
#include <stdlib.h>

void map(int v[], int n, int (*f)(int)) {
    for (int i=0; i<n; i++) {
        v[i] = f(v[i]);
    }
}

int dubleaza(int x) {
    return x*2;
}

int patrat(int x) {
    return x*x;
}

int compar(const void *a, const void *b) {
    const int *a_intstar = (const int*)a;
    const int *b_intstar = (const int*)b;

    int a_int = *a_intstar;
    int b_int = *b_intstar;

    if (a_int < b_int) {
        return -1;
    } else if (a_int == b_int) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n = 8;
    int v[100] = {4,7,8,1,3,10,100,25};

    // map(v, n, dubleaza);
    // map(v, n, patrat);

    qsort(v, n, sizeof(int), compar);

    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }

    // for (int i=0; i<8; i++) {
    //     v[i] = v[i]*2;
    // }

    // for (int i=0; i<8; i++) {
    //     v[i] = v[i]*v[i];
    // }

    // for (int i=0; i<8; i++) {
    //     v[i] = v[i]-1;
    // }
}