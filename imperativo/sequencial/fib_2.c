long long int fib_2(int n) {
    long long int anterior = 0, atual = 1, guardaAtual;

    while(n >= 1) {
        guardaAtual = atual;
        atual = atual + anterior;
        anterior = guardaAtual;

        n--;
    }
}   