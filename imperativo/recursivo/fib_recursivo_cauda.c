long long int calcfib(int n, long long int anterior, long long int atual) {
    if(n == 1) return atual;
    return calcfib(n - 1, atual, anterior + atual);
}

long long int fib_recursivo_cauda(int n) {
    return calcfib(n, 0, 1);
}