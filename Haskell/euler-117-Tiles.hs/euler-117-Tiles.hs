import System.Environment (getArgs)

main :: IO ()
main = do
    args <- getArgs
    case args of
        [arg] -> putStrLn $ show (ways (read arg))
        _     -> putStrLn "Usage: runhaskell <filename.hs> <n>"

ways :: Int -> Integer
ways 0 = 1
ways n = sum $ take (min n 4) $ drop (max (n-4) 0) waysMemo

waysMemo :: [Integer]
waysMemo = map ways [0..]
