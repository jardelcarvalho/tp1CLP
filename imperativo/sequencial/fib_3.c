long long int fib_3(int n) {
    long long int anterior = 0, atual = 1, guardaAtual;

    loop:
        guardaAtual = atual;
        atual = atual + anterior;
        anterior = guardaAtual;

        if(--n >= 1) 
            goto loop;
}   