#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("aici\n");
    int *my_null_pointer=NULL;
    printf("234\n");
    int x = *my_null_pointer;
    printf("asasdad\n");
    printf(" -- x este %d\n", x);

    char *cifre="0123456789";
    char *delimitators=" ,!.";
    char str[100] = "Ana are 010 mere, 20 de pere, 100 de portocale!";
    
    char str_copy[100];
    strcpy(str_copy, str);
    
    // int v[100] = {1,2,3,4};

    // cifre[0]=' ';

    char *p = strpbrk(str, cifre);
    printf("Am gasit prima aparitie a unei cifre din setul %s\n", cifre);
    printf("Incepe aici: %s\n", p);
    printf("Am sarit peste %ld caractere din sirul initial\n", p-str);
    printf("Din acest punct au ramas in sir %ld caractere din %ld cate sunt in total\n", strlen(p), strlen(str));

    // impartim sirul in cuvinte cu strtok
    // si calculam suma tuturor numerelor 
    int sum = 0;

    p = strtok(str, delimitators);
    while (p) {
        printf("Urmatorul cuvant: %s --", p);

        int current_number_atoi = atoi(p);
        char *nr_end = NULL;
        int current_number_strtol = strtol(p, &nr_end, 0);
        printf("Numarul asociat: %d / %d, numar care ocupa %ld caractere\n", 
            current_number_atoi, current_number_strtol,
            nr_end-p);
        sum += current_number_strtol;

        p = strtok(NULL, delimitators);
    }
    printf("Suma este %d\n", sum);

    // sa gasim toate aparitiile unui subsir
    char subsir[100] = "re";
    strcpy(str, str_copy);

    p = strstr(str, subsir);
    while (p) {
        printf("Urmatoarea aparitie a subsirului %s este la pozitia %ld\n", subsir, p-str);
        p = strstr(p+strlen(subsir), subsir);
    }

    // char sir_citit[20];
    // fgets(sir_citit, 20, stdin);
    // printf("__%s__\n", sir_citit);
    // printf("length: %ld\n", strlen(sir_citit));

    char user_password[20];
    fgets(user_password, 20, stdin);
    // user_password contine \n la final!!!
    if (user_password[strlen(user_password)-1] == '\n') {
        user_password[strlen(user_password)-1] = '\0';
    } else {
        printf("parola e prea lunga!\n");
        return -1;
    }
    char *correct_password="cactus";
    if (strcmp(user_password, correct_password) == 0) {
        printf("Corect!\n");
    } else {
        printf("Incorect!\n");
    }
}