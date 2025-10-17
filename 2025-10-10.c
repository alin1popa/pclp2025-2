#include <stdio.h>
int main() {
    // int a = -5;
    // unsigned int b = 3;
    // int result = a / b;
    // printf("%d\n", result);

    // printf("%0+10.2lf\n", 5.0);

    // int i;
    // for (i=0; i<10; i++);
    // {
    //     printf("%d ", i*i);
    // }

    // int x=65;
    // switch(x) {
    //     // case 48: printf("65\n"); break;
    //     case '0': printf("asdad\n"); break; 
    // }

    for (int i=1; i<=10; i++) {
        printf("%d ", i);
    }

    int i=1;
    if (i<=10)
        do {
            // if (i<=10) break;
            printf("%d ", i);
            i++;
        } while (i<=10);

    return 0;
}
