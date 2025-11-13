#include <stdio.h>
#include <stdlib.h>

int comparare(const void *a, const void *b) {
    // int *a_intptr = (int*)a;
    // int *b_intptr = (int*)b;

    // int a_int = *a_intptr;
    // int b_int = *b_intptr;

    // return a_int - b_int;

    return *(int*)a-*(int*)b;    
}

int main() {
    // citim un vector de numere int pozitive
    // scopul final: il sortam
    // nu stim dinainte cate numere citim
    // citirea se opreste la intalnirea numarului 0

    // implementare care realoca array-ul
    // dubland dimensiunea de fiecare data cand se depaseste
    // capacitatea alocata

    // TODO
    // la citirea unui numar negativ e.g. -5
    // asta inseamna stergerea elementului cu valoarea 5 din vector
    // am vrea ca prin mai multe stergeri consecutive
    // si capacitatea sa se reduca la 1/2 atunci cand nr de elemente
    // din vector ajunge la 1/4 
    
    int *v = NULL;
    int capacitate=0; // todo
    int n=0;
    int number;

    scanf("%d", &number);

    while (number > 0) {
        if (n < capacitate) {
            v[n++] = number;
        } else {
            capacitate = capacitate > 0 ? capacitate * 2 : 1;
            // capacitate = capacitate*2+1;
            int *v_temp = realloc(v, capacitate*sizeof(int));
            if (v_temp == NULL) {
                free(v);
                printf("ne pare rau asta este\n");
                return -1;
            }
            v = v_temp;
            v[n++] = number;
        }

        scanf("%d", &number);
    }

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