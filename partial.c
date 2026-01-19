#include <stdio.h>

// int f1(char **addr_p) {
//     // citeste un sir de lungime arbitrara
//     // pana la intalnirea caracterului \n
//     // sorteaza independent consoanele si vocalele
//     // pastrand pozitia
//     // sirul poate contine orice caractere
//     // functia seteaza adresa sirului prin addr_p
//     // returneaza diferenta in valoare absoluta 
//     // intre nr consoane si nr vocale

// }

#include <stdlib.h>
int main() {
    int **m = malloc(10 * sizeof(int*));
    for (int i=0; i<10; i++)
        m[i] = malloc(20*sizeof(int));

    printf("%p\n", &(m[3][0]));
    m[3][0] = 'a';
    char **p = m+4;
    printf("%c\n", *(p[-1]));
}