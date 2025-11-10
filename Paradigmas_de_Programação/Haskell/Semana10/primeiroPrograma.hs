module PrimeiroPrograma where

--Desafio:

num :: Int -> Float
num 1 = 2.0
num 2 = 3.0
num 3 = 4.0
num 4 = 5.0
num 5 = 6.0

somaRecursiva :: Int -> Float
somaRecursiva 6 = 0
somaRecursiva n = num n + somaRecursiva (n+1)

media :: Int -> Float
media n = somaRecursiva 1 / fromIntegral n