#include <stdio.h>

// void insert(int v[], int *addr_n, int elem, int poz) {
//     for (int i=(*addr_n); i>poz; i--) {
//         v[i] = v[i-1];
//     }
//     v[poz] = elem;
//     (*addr_n)++;
// }

// void sort(int v[], int n) {
//     for (int i=0; i<n; i++) {
//         for (int j=i+1; j<n; j++) {
//             if (v[i]>v[j]) {
//                 int aux = v[i];
//                 v[i] = v[j];
//                 v[j] = aux;
//             }
//         }
//     }
// }

int main() { 
    // int a[10][20];
    // int n,m;
    // scanf("%d%d", &n, &m);
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         scanf("%d", &(a[i][j]));
    //     }
    // }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    int n = 10;
    int a[10][10];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            a[i][j] = 0;
            // if (i==j) {
            //     a[i][j]=1;
            // } else if (j > n-1-i) {
            //     a[i][j]=2;
            // } else {
            //     a[i][j]=0;
            // }
        }
    }

    for (int i=0; i<n; i++) {
        a[i][i] = 1;
    }
    for (int i=1; i<n; i++) {
        for (int j=n-i; j<n; j++) {
            a[i][j] = 2;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // int k3[10][20];

    // int v[100];

    // int n;
    // scanf("%d", &n);
    // for (int i=0; i<n; i++) {
    //     scanf("%d", &v[i]);
    // }

    // int elem = 7;
    // for (int i=0; i<n; i++) {
    //     if (v[i] == elem) {
    //         printf("Am gasit pe pozitia %d\n", i);
    //         break;
    //     }
    // }

    // insert(v, &n, 7, 2);

    // for (int i=0; i<n; i++) {
    //     printf("%d ", v[i]);
    // }

    // sort(v, n);
    
    // for (int i=0; i<n; i++) {
    //     printf("%d ", v[i]);
    // }

    // printf("\n%p\n", &(v[0]));
    // printf("%p\n", &(v[1]));
    // printf("%p\n", &(v[2]));
    // printf("%p\n", v);

    // int *p0 = v; //*p0 // *v
    // int *p1 = p0+1; //*p1 // al doilea element
    // // *p1 === *(p0+1) === *(v+1)
    // printf("%d\n", *v);

    // // v[i] ==== *(v+i) === *(i+v) === i[v]
    // printf("%d\n", 0[v]);
}