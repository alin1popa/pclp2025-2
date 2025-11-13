#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// se citesc de la tastatura linii de text
// programul se opreste la intalnirea primei linii goale
// liniile pot avea lungime arbitrara
// vrem sa sortam liniile dupa numarul de aparitii
// ale unui caracter dat
// dar 
// luam in considerare numai aparitiile caracterului
// din interiorul cuvintelor (fara prima si ultima litera)

char* citeste_linie() {
    int current_size = 100; // dimensiunea initiala a sirului
    int step = 100; // cu cat realocam la fiecare pas

    char *s = malloc(current_size);
    if (!s) {
        printf("eroare la alocare\n");
        return NULL;
    }
    fgets(s, current_size, stdin);
    // fgets se opreste ori cand a citit current_size caractere
    // ori cand a intalnit \n, caz in care \n apare in string

    while (s[strlen(s)-1] != '\n') {
        // mai avem de citit
        current_size += step; // marim size-ul
        char *p = realloc(s, current_size); // realocam
        if (!p) {
            printf("eroare la REalocare\n");
            free(s);
            return NULL;
        }
        s = p;
        p = NULL;
        fgets(s+strlen(s), step, stdin); //merge si s+current_size
    }

    // am alocat pana acum un multiplu intreg de 100
    // putem scapa de spatiul nefolosit de la final? da
    // realocam sirul
    char *p = realloc(s, strlen(s)+1);
    if (!p) {
        printf("eroare la REalocare\n");
        free(s);
        return NULL;
    }

    s = p;
    p = NULL;

    return s;
}

char caracter_global;

int numara_aparitii_caracter_in_interior_cuv(char *s) {
    int numar = 0;
    char *p = strchr(s, caracter_global);
    while (p) {
        int este_la_margine = 0;
        // if (p[1] == ' ') {
        //     este_la_margine = 1;
        // }
        // problema: un cuvant se poate termina si cu alte lucruri
        // nu doar cu spatiu
        // gen: !, ., virgula, \0, \n, etc
        if (strchr(".,!;\n ", p[1]) || p[1] == '\0') {
            este_la_margine = 1;
        }
        if (p==s || strchr(".,!;\n ", p[-1])) {
            este_la_margine = 1;
        } 

        if (!este_la_margine) {
            numar++;
        }
        p = strchr(p+1, caracter_global);
    }
    return numar;
}

int comparare_linii_dupa_nr_caractere_in_interior_cuv(const void *a, const void *b) {
    // noi stim ca acesti doi pointeri reprezinta pointeri la doi char*
    // putem sa ii castam
    char **a_casted = (char**)a;
    char **b_casted = (char**)b;

    // acum putem sa dereferentiem ca sa obtinem sirurile
    char *a_sir = *a_casted;
    char *b_sir = *b_casted;

    int a_count = numara_aparitii_caracter_in_interior_cuv(a_sir);
    int b_count = numara_aparitii_caracter_in_interior_cuv(b_sir);

    return a_count - b_count;
}

int main() {
    caracter_global = 'a';

    // 1. citirea liniilor
    // prima intrebare: cum stocam liniile?
    // r: intr-un vector (de linii)
    char **linii = NULL;
    int N = 0;
    // a doua intrebare: cate linii avem?
    // r: nu stim, ne oprim cand dam de o linie goala
    // putem face matrice alocata dinamic, fiecare rand este cate o linie
    // fiecare rand are dimensiune diferita

    // ar trebui sa incepem cu citirea unei singure linii
    // ca deja prima linie poate fi goala
    char *linie_curenta;

    linie_curenta = citeste_linie();
    if (!linie_curenta) {
        printf("n-a mers\n");
        return -1;
    }
    // printf("%s\n", linie_curenta);

    // la citirea unei linii goale, linia va contine doar \n si \0
    // deci strlen(linie) o sa fie 1
    while (strlen(linie_curenta) != 1) {
        N++;
        char **linii_tmp = realloc(linii, N*sizeof(char*));
        if (!linii_tmp) {
            printf("eroare la realocarea matricii\n");
            for (int i=0; i<N-1; i++) {
                free(linii[i]);
            }
            free(linii);
        }
        linii = linii_tmp;
        linii[N-1] = linie_curenta;
        linie_curenta = citeste_linie();
    }

    printf("--------\n");
    for (int i=0; i<N; i++) {
        printf("Linia %d: %s", i, linii[i]);
    }
    
    // 2.1 numararea aparitiilor caracterului in interioriul cuvintelor
    // 2.2 sortarea liniilor
    qsort(linii, N, sizeof(char*), comparare_linii_dupa_nr_caractere_in_interior_cuv);

    // 3. afisarea liniilor sortate
    printf("----sortate----\n");
    for (int i=0; i<N; i++) {
        printf("Linia %d: %s", i, linii[i]);
    }
}