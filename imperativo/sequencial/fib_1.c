long long int fib_1(int n) {
    long long int anterior = 0, atual = 1, guardaAtual;

    for(; n >= 1; n--) {
        guardaAtual = atual;
        atual = atual + anterior;
        anterior = guardaAtual;
    }
}
