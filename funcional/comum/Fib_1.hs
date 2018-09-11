-- Fibonacci 
-- Recursão comum
-- 1ª implementação

module Fib_1 where 

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)
