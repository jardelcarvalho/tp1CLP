-- Fibonacci
-- Recusão em cauda
-- 4ª implementação

module Fib_cauda_4 where 

fib :: Int -> Int
fib n = fibaux n 0 1

fibaux :: Int -> Int -> Int -> Int
fibaux n a b
    |n == 1 = b
    |otherwise = 
        let
            ant = b
            termo = a + b
        in 
            fibaux (n - 1) ant termo