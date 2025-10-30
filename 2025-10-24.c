#include <stdio.h>
#include <stdlib.h>

int main() {
    // int n;
    // scanf("%d", &n);

    // int *a = malloc(n*sizeof(int));
    // if (a == NULL) {
    //     printf("eroare la alocare\n");
    //     return 1;
    // }
    // *a = 5;
    // a[1] = 10;

    // printf("%p\n", a);
    // printf("%d\n", *a);

    // // am nevoie de n*2
    // // int *a2 = malloc(2*n*sizeof(int));
    // // if (a2 == NULL) {...}
    // // for (int i=0; i<n; i++)
    // //     a2[i] = a[i];
    // // free(a);
    // // a = a2;
    // // n*=2;

    // int *a2 = realloc(a, n*2*sizeof(int));
    // if (a2 == NULL) {
    //     printf("a esuat realloc\n");
    //     free(a);
    //     return 1;
    // }
    // a = a2;
    // n*=2;



    // free(a);
    // a = NULL;

    int a=5, b=3;
    int **m;
    m = malloc(a * sizeof(int*));
    if (m==NULL) {
        return 1;
    }
    for (int i=0; i<a; i++) {
        m[i] = malloc(b * sizeof(int));
        if (m[i]==NULL) {
            for (int j=0; j<i; j++) {
                free(m[j]);
            }
            free(m);
            return 1;
        }
    }
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            m[i][j] = i+j;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}