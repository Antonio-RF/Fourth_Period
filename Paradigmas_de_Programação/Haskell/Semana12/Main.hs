module Main where
import Lista3

main :: IO ()
main = do
    print(funcMap recebeNomeSR ["Carlos", "Joao"])
    print (funcMap recebeNomeSRA ["Maria", "Paula"])
    print (funcMap recebeNomeSRTA ["Ana", "Clara"])

    