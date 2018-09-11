
import Fib_1
import Fib_2
import Fib_3
import Fib_cauda_1
import Fib_cauda_2
import Fib_cauda_3
import Fib_cauda_4

import System.IO
import Data.Char
import Control.Exception
import Data.Time

imprimir :: String -> String -> IO ()
imprimir dado caminho = do
    arq <- openFile caminho AppendMode
    hPutStrLn arq dado
    hClose arq

tiraS :: String -> String 
tiraS (h:t)
    |h == 's' = []
    |otherwise = [h] ++ tiraS t

teste :: Int -> Int -> IO ()
teste n tam = do
    let entrada = n
    inicio <- getCurrentTime
    let r = (Fib_1.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_1," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_2.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_2," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_3.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_3," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_cauda_1.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_c_1," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_cauda_2.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_c_2," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_cauda_3.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_c_3," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"
    --
    inicio <- getCurrentTime
    let r = (Fib_cauda_4.fib entrada)
    fim <- getCurrentTime
    let out = "Fib_c_4," ++ tiraS (show ((diffUTCTime fim inicio) * 1000)) ++ "," ++ (show entrada)
    imprimir out "resultados/haskell.csv"

exec :: [Int] -> Int -> IO ()
exec (h:[]) tam = teste h tam
exec (h:t) tam = do
    teste h tam
    exec t tam

main = do
    arq <- openFile "resultados/haskell.csv" WriteMode
    hClose arq

    imprimir "Tipo,Tempo(milisec),N" "resultados/haskell.csv"
    let n = 5
    exec [10, 20, 30, 40, 50] n

    --imprimir (show (Fib_1.fib 18)) "resultados/haskell.csv"
    --print (Fib_2.fib 18)
    --print (Fib_3.fib 18)
    --print (Fib_cauda_1.fib 18)
    --print (Fib_cauda_2.fib 18)
    --print (Fib_cauda_3.fib 18)
    --print (Fib_cauda_4.fib 18)


