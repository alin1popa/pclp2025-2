#include <stdio.h>
#include <stdlib.h>

int main() {
    // int n = 20;
    // fwrite(&n, sizeof(int), 1, f_out);
    
    int v[100];
    int n;

    // citim un caracter: s (save) sau l (load)
    // daca se citeste s, atunci citim un numar n
    // apoi n inturi in vector
    // si salvam in fisier (binar)
    // daca se citeste l, atunci citim vectorul din fisier

    char mode;
    scanf("%c", &mode);

    if (mode == 's') {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        FILE *f = fopen("./my_output_file.bin", "wb");
        fwrite(&n, sizeof(int), 1, f);
        fwrite(v, sizeof(int), n, f);
        fclose(f);
        FILE *f2 = fopen("./my_output_file.txt", "w");
        for (int i=0; i<n; i++) {
            printf("%d ", v[i]);
            fprintf(f2, "%d ", v[i]);
        }
        printf("\n");
    } else {
        FILE *f = fopen("./my_output_file.bin", "rb");
        fread(&n, sizeof(int), 1, f);
        fread(v, sizeof(int), n, f);
        fclose(f);
        for (int i=0; i<n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    return 0;
}