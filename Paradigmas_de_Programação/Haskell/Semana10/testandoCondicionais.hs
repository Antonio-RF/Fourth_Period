module TestandoCondicionais where

--Exercise 2:

permissaoBeber :: Int -> String
permissaoBeber a = if a >= 18
    then "Pode beber"
    else "NAO pode beber"

permissaoBeber2 :: Int -> String
permissaoBeber2 a
    | a >= 18 = "Pode beber"
    | otherwise = "NAO pode beber"

verificaNumero :: Int -> String
verificaNumero a = if a > 0
    then "positivo"
    else if a == 0 then "zero"
    else "negativo"

verificaNumero2 :: Int -> String
verificaNumero2 a
    | a > 0 = "positivo"
    | a == 0 = "zero"
    | otherwise = "negativo"

verificaBissexto :: Int -> Bool
verificaBissexto a = if ((mod a 4 == 0 && mod a 100 /= 0) || mod a 400 == 0)
    then True
    else False

verificaBissexto2 :: Int -> Bool
verificaBissexto2 a = if ((div4 && div100) || div400)
    then True
    else False

    where
        div4 = mod a 4 == 0
        div100 = mod a 100 /= 0
        div400 = mod a 400 == 0

verificaBissexto3 :: Int -> Bool
verificaBissexto3 a
    | ((div4 && div100) || div400) = True
    | otherwise = False

    where
        div4 = mod a 4 == 0
        div100 = mod a 100 /= 0
        div400 = mod a 400 == 0

--