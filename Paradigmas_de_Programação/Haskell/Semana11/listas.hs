module Listas where

somaElementos :: [Int] -> Int
somaElementos [] = 0
somaElementos(h:c) = h + somaElementos c

removePares :: [Int] -> [Int]
removePares [] = []
removePares(h:c)
    | mod h 2 == 0 = removePares c
    | otherwise = h : removePares c 

inverteLista :: [Int] -> [Int]
inverteLista [] = []
inverteLista(h:c) = inverteLista c ++ [h]

apenasA :: [String] -> [String]
apenasA [] = []
apenasA(h:c)
    | head h == 'A' = h : apenasA c
    | otherwise = apenasA c

lista1a :: Int -> [Int]
lista1a n = [x | x <- [0,3..n]]

lista1b :: Int -> [[Int]]
lista1b n = [[x] | x <- [1..n]]