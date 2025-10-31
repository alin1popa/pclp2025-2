#include <stdio.h>
#include <stdlib.h>

void dezaloca_matricea(int ***ptr_m, int nrRows) {
    for (int i=0; i<nrRows; i++) {
        free((*ptr_m)[i]);
    }
    free((*ptr_m));
    *ptr_m=NULL;
}

int main() {
    int m2[10][20];

    // adresa matricii m2 = un vector de randuri
    printf("%p\n", m2);
    // pointer la al doilea rand
    printf("%p\n", (m2+1)  );
    // efectiv al doilea rand (aceeasi adresa, dar este un rand)
    // este de fapt un vector de inturi
    // la aritmetica, va face decay intr-un pointer la **UN** int
    printf("%p\n", (m2[1]) );

    // inca un rand mai incolo (adica al treilea rand)
    printf("%p\n", (m2+1)+1  );
    // pointer la al doilea int din al doilea rand
    printf("%p\n", (m2[1])+1 );

    // un array nu face decay la sizeof
    // deci aplicam sizeof pe intregul array = 20*4=80 bytes
    printf("%ld\n", sizeof(m2[1]));
    // m2 a facut decay pt operatia aritmetica deci e un pointer
    // are fix 8 bytes
    printf("%ld\n", sizeof(m2+1));

    return 0;

    int **m; // matrice alocata dinamic
    int nrRows, nrCols;
    scanf("%d%d", &nrRows, &nrCols);

    // alocam vectorul de randuri (adica m)
    m = malloc(nrRows * sizeof(int*));
    if (m == NULL) {
        printf("eroare la alocarea m\n");
        return -1;
    }

    // alocam fiecare rand
    for (int i=0; i<nrRows; i++) {
        m[i] = malloc(nrCols * sizeof(int));
        if (m[i] == NULL) {
            printf("eroare la alocarea m[%d]\n", i);
            // daca n-a mers alocarea unui rand m[i]
            // dezalocam restul matricii
            // adica toate randurile m[j] pt j=0..i-1
            // si m
            for (int j=0; j<i; j++) {
                free(m[j]);
            }
            free(m);
            return -1;
        }
    }

    // citirea matricii
    for (int i=0; i<nrRows; i++) {
        for (int j=0; j<nrCols; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    // realocam m pentru adaugarea unui nou rand
    int **m_temp = realloc(m, (nrRows+1) * sizeof(int*));
    if (!m_temp) {
        // dezalocarea matricii
        dezaloca_matricea(&m, nrRows);
        return -1;
    }
    m = m_temp;
    nrRows++;
    // alocam noul rand format
    m[nrRows-1] = malloc(nrCols * sizeof(int));
    if (!m[nrRows-1]) {
        // daca n-a mers, dezalocam doar celelalte randuri,
        // nu si randul care tocmai n-a mers
        dezaloca_matricea(&m, nrRows-1);
        return -1;
    }

    for (int j=0; j<nrCols; j++) {
        scanf("%d", &m[nrRows-1][j]);
    }

    // afisarea matricii
    for (int i=0; i<nrRows; i++) {
        for (int j=0; j<nrCols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // dezalocarea matricii
    dezaloca_matricea(&m, nrRows);

    return 0;
}