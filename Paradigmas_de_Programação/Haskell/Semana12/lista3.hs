module Lista3 where

--Exercise 1:
funcao1_0 :: (String, String, Char) -> String
funcao1_0 (a, _, _) = a

funcao1_1 :: (String, String, Char) -> String
funcao1_1 (_, b, _) = b

funcao1_2 :: (String, String, Char) -> Char
funcao1_2 (_, _, c) = c
--
--Exercise 2:

base :: Int -> (String, String, Char)
base x
    | x == 1 = ("joao", "mestre", 'm')
    | x == 2 = ("jonas", "doutor", 'm')
    | x == 3 = ("joice", "mestre", 'f')
    | x == 4 = ("janete", "doutor", 'f')
    | x == 5 = ("jocileide", "doutor", 'f')
    | otherwise = ("ninguem", "nada", 'x')

contMestre :: Int -> Int
contMestre 6 = 0
contMestre n = if cargo == "mestre"
    then 1 + contMestre (n+1)
    else contMestre(n+1)
    where
        (_, cargo, _) = base n

contDoc :: Int -> Int
contDoc 6 = 0
contDoc n = if cargo == "doutor"
    then 1 + contDoc (n+1)
    else contDoc (n+1)
    where
        (_, cargo, _) = base n

contMD :: String -> Int -> Int
contMD _ 6 = 0
contMD titulo n = if (titulo == cargo)
    then 1 + contMD titulo (n+1)
    else contMD titulo (n+1)
    where
        (_, cargo, _) = base n

cont :: String -> Char -> Int -> Int
cont _ _ 6 = 0
cont titulo sex n = if (titulo == cargo && sex == genero)
    then 1 + cont titulo sex (n+1)
    else cont titulo sex (n+1)
    where
        (_, cargo, genero) = base n
--
--Exercise 3:

type Nome = String
type Titulo = String
type Genero = Char
type Pesquisador = (Nome, Titulo, Genero)
type Grupo = [Pesquisador]

formaLista :: Int -> Grupo
formaLista 6 = []
formaLista n = (name, cargo, sex) : formaLista (n+1)
    where
        (name, cargo, sex) = base n

apenasDoutor :: Grupo -> Grupo
apenasDoutor g = [(n, t, k) | (n, t, k) <- g, t == "doutor"]

--
--Exercise 4:

recebeNomeSR :: String -> String
recebeNomeSR s = "Sr. " ++ s

recebeNomeSRA :: String -> String
recebeNomeSRA s = "Sra. " ++ s

recebeNomeSRTA :: String -> String
recebeNomeSRTA s = "Srta. " ++ s

funcMap :: (String -> String) -> [String] -> [String]
funcMap _ [] = []
funcMap f (h: c) = f h : funcMap f c

--
--Exercise 5:

recebeRealS :: Int -> Bool
recebeRealS a = if a > 0
    then True
    else False

recebeRealN :: Int -> Bool
recebeRealN a = if a < 0
    then True
    else False

recebeReal0 :: Int -> Bool
recebeReal0 a
    | a == 0 = True
    | otherwise = False

funcFilt :: [Int] -> (Int -> Bool) -> [Int]
funcFilt [] _ = []
funcFilt (h:c) f = if f h
    then h : funcFilt c f
    else funcFilt c f