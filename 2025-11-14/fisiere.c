#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_out = fopen("./my_output_file.txt", "w");
    int n = 20;
    // fprintf(f_out, "Numarul magic este %d\n", n);
    fprintf(f_out, "%d", n);
    return 0;
}