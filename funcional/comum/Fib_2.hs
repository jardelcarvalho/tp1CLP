-- Fibonacci 
-- Recursão comum
-- 2ª implementação

module Fib_2 where 

fib :: Int -> Int
fib n
    |n == 0 = 0
    |n == 1 = 1
    |otherwise = fib (n - 1) + fib (n - 2)