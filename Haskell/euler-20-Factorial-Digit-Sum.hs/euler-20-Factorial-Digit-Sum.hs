import System.Environment (getArgs)

sumDigits :: Integer -> Integer
sumDigits n = sumDigits' n 0
    where sumDigits' 0 acc = acc
          sumDigits' n acc = sumDigits' (div n 10) (acc + (mod n 10))

factorial :: Integer -> Integer
factorial n = foldr (*) 1 [1..n]

main :: IO ()
main = do
    args <- getArgs
    case args of
        [arg] -> do
            let n = read arg :: Integer
            print $ sumDigits $ factorial n
        _ -> putStrLn "Usage: runghc euler-20-Factorial-Digit-Sum <integer>"
