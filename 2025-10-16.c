#include <stdio.h>

// void f() {
//     printf("ana ");
//     printf("are ");
//     printf("mere ");
//     printf("\n");
// }

// int par(int n);
// int impar(int n);

// int par(int n) {
//     if (n==0) {
//         return 1;
//     }
//     return impar(n-1);
// }
// int impar(int n) {
//     if (n==0) {
//         return 0;
//     }
//     return par(n-1);
// }


int factorial_intern(int p, int n) {
    if (n==0) {
        return p;
    } else {
        return factorial_intern(p*n, n-1);
    }
}

int factorial(int n) {
    return factorial_intern(1, n);
}

// factorial(1, n)


// int factorial(int n) {
//     if (n==0) {
//         return 1;
//     } else {
//         return n * factorial(n-1);
//     }
// }

// int fibo(int n) {
//     if (n==0) {
//         return 0;
//     } else if (n==1) {
//         return 1;
//     }
//     return fibo(n-1) + fibo(n-2);
// }

int f(int *addr_x) {
    (*addr_x)++;
}

int main() {

    int x=5;
    f(&x);
    printf("%d\n", x);
    // int v[20];
    // int n;

    // printf("Introduceti n:\n");
    // f();
    // scanf("%d", &n);
    // for (int i=0; i<n; i++) {
    //     scanf("%d", &v[i]);
    // }

    // for (int i=0; i<n; i++) {
    //     v[i] = v[i]*v[i];
    // }

    // for (int i=0; i<n; i++) {
    //     printf("%d ", v[i]);
    // }
    // printf("\n");
    // printf("heya \n");
    // return 0;

/// ------------------------------
    // int p=1;
    // int n=5;
    // for (int i=1; i<=n; i++) {
    //     p*=i;
    // }
    // printf("%d\n", p);

    // printf("%d\n", factorial(n));

    // printf("%d\n", fibo(42));

    // // fibo iterativ
    // int a=0, b=1, c;
    // for (int i=2; i<=120; i++) {
    //     c = a + b;
    //     a = b;
    //     b = c;
    // }
    // printf("%d\n", b);

    // printf("%d %d %d", par(15), par(16), impar(15));

    // int x=5;
    // printf("%p\n", &x);
}