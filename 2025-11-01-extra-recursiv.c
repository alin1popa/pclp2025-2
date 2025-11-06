#include <stdio.h>

// functie care returneaza cifra minima a unui nr
// recursiv
int min(int a, int b) {
    return a < b ? a : b;
}

int cifra_minima_recursiv(int nr) {
    if (nr < 10) {
        return nr;
    }
    return min(cifra_minima_recursiv(nr/10), nr%10);
}

int cifra_minima_nerecursiv(int nr) {
    int cif_min = 10;
    // int ultimele_doua_cifre = nr % 100;

    // if (nr < 10)
    //     return nr;

    // for (; nr>0; ) {
    do {
        int ultima_cifra = nr % 10;
        // if (ultima_cifra < cif_min) {
        //     cif_min = ultima_cifra;
        // }
        // (expresie) ? (value if true) : (value if false)
        cif_min = ultima_cifra < cif_min ? ultima_cifra : cif_min; 
        nr /= 10;
    } while (nr > 0);

    return cif_min;
}



int main() {
    // printf("aabc\n");
    printf("%d\n", cifra_minima_recursiv(12345));
    printf("%d\n", cifra_minima_recursiv(54321));
    printf("%d\n", cifra_minima_recursiv(9996999));
    printf("%d\n", cifra_minima_recursiv(0));
    return 0;
}