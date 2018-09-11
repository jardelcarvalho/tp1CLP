-- Fibonacci 
-- Recursão em cauda
-- 3ª implementação

module Fib_cauda_3 where 

fib :: Int -> Int
fib n = calcfib n 0 1

calcfib :: Int -> Int -> Int -> Int
calcfib n a b = if n == 0 then a 
                else calcfib (n - 1) b (a + b)
