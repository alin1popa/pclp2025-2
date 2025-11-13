#include <stdio.h>



int main() {
    int a[100][100], b[100][100], s[100][100], p[100][100];

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            s[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // pt fiecare element din matricea produs
            int suma = 0;
            for (int k=0; k<n; k++) {
                suma += a[i][k] * b[k][j];
            }
            p[i][j] = suma;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}