module Tuplas where

questao1 :: Int -> (Int, Int, Int, Int)
questao1 n = (2*n, 3*n, 4*n, 5*n)

questao2 :: Int -> (Int, String)
questao2 n = if mod n 2 == 0
    then (div n 2, "Par")
    else (div n 2, "Impar")

questao2_1 :: Int -> (Int, String)
questao2_1 n
    | mod n 2 == 0 = (div n 2, "Par")
    | otherwise = (div n 2, "Impar")

questao3 :: [Int] -> (Int, Int)
questao3 [] = (0,0)
questao3(h:c)
    | h > 0 = (positivo+h, negativo)
    | otherwise = (positivo, negativo+h)
    where
        (positivo, negativo) = questao3 c

type Localizacao = String
type Nota = Int
type Nome = String
type Ponto_turistico = (Localizacao, Nota, Nome)
type Lista_pontos_turisticos = [Ponto_turistico]

questao4 :: Lista_pontos_turisticos -> Int -> Lista_pontos_turisticos
questao4 ponto nota = [(loc, media, nome) | (loc, media, nome) <- ponto, media >= nota]
    