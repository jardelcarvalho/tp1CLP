#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../sequencial/fib_1.c"
#include "../sequencial/fib_2.c"
#include "../sequencial/fib_3.c"
#include "../recursivo/fib_recursivo.c"
#include "../recursivo/fib_recursivo_cauda.c"

int CASOS_TESTE[] = {10, 20, 30, 40, 50};
int N = 5;

int main(int argc, char **argv) {

    /*int n = atoi(*(argv + 1));

    printf("%lld\n", fib_1(n));
    printf("%lld\n", fib_2(n));
    printf("%lld\n", fib_3(n));
    printf("%lld\n", fib_recursivo(n));
    printf("%lld\n", fib_recursivo_cauda(n));*/

    double variacao, total_1, total_2, total_3, total_r, total_r_c;
    total_1 = total_2 = total_3 = total_r = total_r_c = .0f;

    struct timeval tv1, tv2;
    
    FILE *fout = fopen("resultados/c.csv", "w");
    FILE *medias = fopen("resultados/medias_c.csv", "w");
    fprintf(fout, "Tipo,Tempo(milisec),N\n");

    for(int i = 0; i < N ; i++) {
        gettimeofday(&tv1, NULL);
        fib_1(CASOS_TESTE[i]);
        gettimeofday(&tv2, NULL);
        variacao = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        total_1 += variacao;
        fprintf(fout, "Fib_1,%lf,%d\n", variacao, CASOS_TESTE[i]);

        gettimeofday(&tv1, NULL);
        fib_2(CASOS_TESTE[i]);
        gettimeofday(&tv2, NULL);
        variacao = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        total_2 += variacao;
        fprintf(fout, "Fib_2,%lf,%d\n", variacao, CASOS_TESTE[i]);

        gettimeofday(&tv1, NULL);
        fib_3(CASOS_TESTE[i]);
        gettimeofday(&tv2, NULL);
        variacao = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        total_3 += variacao;
        fprintf(fout, "Fib_3,%lf,%d\n", variacao, CASOS_TESTE[i]);

        gettimeofday(&tv1, NULL);
        fib_recursivo(CASOS_TESTE[i]);
        gettimeofday(&tv2, NULL);
        variacao = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        total_r += variacao;
        fprintf(fout, "Fib_r,%lf,%d\n", variacao, CASOS_TESTE[i]);

        gettimeofday(&tv1, NULL);
        fib_recursivo_cauda(CASOS_TESTE[i]);
        gettimeofday(&tv2, NULL);
        variacao = (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        total_r_c += variacao;
        fprintf(fout, "Fib_r_c,%lf,%d\n", variacao, CASOS_TESTE[i]);
    }

    fprintf(medias, "Tipo.Media(milisec).Div\n");
    fprintf(medias, "Fib_1,%lf,%d\n", total_1 / (float) N, N);
    fprintf(medias, "Fib_2,%lf,%d\n", total_2 / (float) N, N);
    fprintf(medias, "Fib_3,%lf,%d\n", total_3 / (float) N, N);
    fprintf(medias, "Fib_r,%lf,%d\n", total_r / (float) N, N);
    fprintf(medias, "Fib_r_c,%lf,%d\n", total_r_c / (float) N, N);

    fclose(fout);

    return 0;
}
