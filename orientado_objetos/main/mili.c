#include <stdio.h>
#include <stdlib.h>

int main() {
    int milisec = 1000000;

    FILE *arq = fopen("resultados/medias_java_temp.csv", "r");
    FILE *mf = fopen("resultados/medias_java.csv", "w");
    char str1[36];
    long long int t;

    fprintf(mf, "%s", "Tipo.Media(milisec).Div\n");

    fscanf(arq, "%lld", &t);
    fprintf(mf, "Fib_1,%lf,%d\n", ((double) t / milisec) / 5, 5);
    fscanf(arq, "%lld", &t);
    fprintf(mf, "Fib_2,%lf,%d\n", ((double) t / milisec) / 5, 5);
    fscanf(arq, "%lld", &t);
    fprintf(mf, "Fib_3,%lf,%d\n", ((double) t / milisec) / 5, 5);
    fscanf(arq, "%lld", &t);
    fprintf(mf, "Fib_r,%lf,%d\n", ((double) t / milisec) / 5, 5);
    fscanf(arq, "%lld", &t);
    fprintf(mf, "Fib_r_c,%lf,%d\n", ((double) t / milisec) / 5, 5);

    fclose(arq);
    fclose(mf);
}