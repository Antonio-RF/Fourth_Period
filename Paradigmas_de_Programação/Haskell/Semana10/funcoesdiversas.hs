module FuncoesDiversas where

--Exercise 1:

somaQuadrados :: Int -> Int -> Int -> Int
somaQuadrados a b c = a*a + b*b + c*c

somaQuadrados2 :: Int -> Int -> Int -> Int
somaQuadrados2 a b c = a^2 + b^2 + c^2

somaQuadrados3 :: Float -> Float -> Float -> Float
somaQuadrados3 a b c = a**2 + b**2 + c**2

ehimpar :: Int -> Bool
ehimpar a = if mod a 2 == 0
    then False
    else True

ehimpar2 :: Int -> Bool
ehimpar2 a
    | mod a 2 == 0 = False
    | otherwise = True

ehimpar3 :: Int -> Bool
ehimpar3 a = if even a
    then False
    else True

--