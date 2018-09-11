#include <stdio.h>
#include <stdlib.h>

int main (int argv, char **argc){
    FILE *arq = fopen("resultados/haskell.csv", "r");
    FILE *medias = fopen("resultados/medias_haskell.csv", "w");
    double s[7] = {0, 0, 0, 0, 0, 0, 0};
    char str1[128], str2[128];

    fscanf(arq, "%s", &str1[0]);

    for(int i = 0; !feof(arq); ) {
        if(i == 7) i = 0;
        double var;
        char c = ' ';
        for(; c != ','; ) {
            fscanf(arq, "%c", &c);
        }
        fscanf(arq, "%lf,%s\n", &var, &str2[0]);
        s[i++] += var;
    }

    fprintf(medias, "Tipo.Media(milisec).Div\n");

    int N = atoi(*(argc + 1));

    fprintf(medias, "Fib_1,%lf,%d\n", s[0] / (double) N, N);
    fprintf(medias, "Fib_2,%lf,%d\n", s[1] / (double) N, N);
    fprintf(medias, "Fib_3,%lf,%d\n", s[2] / (double) N, N);
    fprintf(medias, "Fib_c_1,%lf,%d\n", s[3] / (double) N, N);
    fprintf(medias, "Fib_c_2,%lf,%d\n", s[4] / (double) N, N);
    fprintf(medias, "Fib_c_3,%lf,%d\n", s[5] / (double) N, N);
    fprintf(medias, "Fib_c_4,%lf,%d\n", s[6] / (double) N, N);

    fclose(arq);
    fclose(medias);

    return 0;
}