module Recursao where

--Exercise 3:

fibonacci :: Int -> Int
fibonacci a = 
    if a == 0 then 0
    else if a == 1 then 1
    else (fibonacci (a-1) + fibonacci (a-2))

contaDigitos :: Int -> Int
contaDigitos a =
    if a == 0 then 0
    else (1 + contaDigitos (a `div` 10))

contaSomaDigitos :: Int -> Int
contaSomaDigitos a =
    if a == 0 then 0
    else (mod a 10 + contaSomaDigitos (a `div` 10))

--