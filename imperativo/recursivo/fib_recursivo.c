long long int fib_recursivo(int n) {
    if(n == 0 || n == 1) return n;
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}