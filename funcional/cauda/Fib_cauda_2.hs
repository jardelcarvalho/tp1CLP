-- Fibonacci 
-- Recursão em cauda
-- 2ª implementação

module Fib_cauda_2 where 

fib :: Int -> Int
fib n = calcfib n 0 1

calcfib :: Int -> Int -> Int -> Int
calcfib n a b
    |n == 0 = a
    |otherwise = calcfib (n - 1) b (a + b)