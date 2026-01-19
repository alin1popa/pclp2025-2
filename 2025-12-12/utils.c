#include <stdio.h>

void print_binary(int x) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        putchar((x & (1 << i)) ? '1' : '0');
    }
}
