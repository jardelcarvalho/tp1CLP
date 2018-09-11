-- Fibonacci
-- Recursão em cauda
-- 1ª implementação

module Fib_cauda_1 where 

fib :: Int -> Int
fib n = calcfib n 0 1

calcfib :: Int -> Int -> Int -> Int
calcfib 0 a _ = a
calcfib n a b = calcfib (n - 1) b (a + b)