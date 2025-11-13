#include <stdio.h>
#include <stdlib.h>

int comparare(const void *a, const void *b) {
    int *a_intptr = (int*)a;
    int *b_intptr = (int*)b;

    int a_int = *a_intptr;
    int b_int = *b_intptr;

    return a_int - b_int;
}

int main() {
    // citim un vector de numere int pozitive
    // scopul final: il sortam
    // nu stim dinainte cate numere citim
    // citirea se opreste la intalnirea numarului 0

    // implementare care realoca array-ul cu cate 1 element
    // de fiecare data cand se citeste un element
    
    int *v = NULL;
    int n=0;
    int number;

    do {
        scanf("%d", &number);

        if (number > 0) {
            int *v_temp = realloc(v, ++n*sizeof(int));
            if (v_temp == NULL) {
                free(v);
                printf("ne pare rau asta este\n");
                return -1;
            }
            v = v_temp;
            v[n-1] = number;
        }
    } while (number > 0);

    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    qsort(v, n, sizeof(int), comparare);
    
    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}