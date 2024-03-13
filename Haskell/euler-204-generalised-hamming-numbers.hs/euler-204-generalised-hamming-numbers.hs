import System.Environment (getArgs)

-- 'isPrimeNumber' checks if a given number is a prime number
isPrimeNumber :: Int -> Bool
isPrimeNumber n
    | n < 2 = False
    | otherwise = all (\i -> n `mod` i /= 0) [2..isqrt n]
    where
        isqrt = floor . sqrt . fromIntegral

-- 'generalisedHammingNumbers' recursively solves the combinations of prime factors
-- to find the count of generalised Hamming numbers within a specified limit
--
-- Parameters:
--   index: Current index in the list of prime factors
--   product: Current product of the prime factors in the combination
--   total: Total count of combinations satisfying the condition
--   primes: List of prime numbers
--   limit: The upper limit for the product in the combinations
generalisedHammingNumbers :: Int -> Int -> Int -> [Int] -> Int -> Int
generalisedHammingNumbers index product total primes limit
    -- If the current product is within the limit, continue the calculation
    | product <= limit =
        -- Recursively calculate combinations for the remaining prime factors
        foldl (\sum nextIndex -> generalisedHammingNumbers nextIndex (product * (primes !! nextIndex)) sum primes limit)
              -- Increment the total count for valid combinations
              (total + 1)
              -- Iterate over the remaining prime factors starting from the current index
              [index..length primes - 1]
    -- If the current product exceeds the limit, stop recursion and return the total count
    | otherwise = total

main :: IO ()
main = do
    -- Get command-line arguments
    args <- getArgs

    -- Check if two command-line arguments are provided
    case args of
        [primetypeStr, limitStr] -> do
            -- Attempt to parse the first and second arguments as integers
            case reads primetypeStr of
                [(primetype, "")] -> do
                    case reads limitStr of
                        [(limit, "")] -> do
                            -- Find prime numbers up to the specified type
                            let primeNumbers = filter isPrimeNumber [1..primetype]
                            -- Calculate the result using the generalisedHammingNumbers function
                            let result = generalisedHammingNumbers 0 1 0 primeNumbers limit
                            -- Print the result
                            print result
                        _ -> putStrLn $ "Error: Invalid second input."
                _ -> putStrLn $ "Error: Invalid first input."
        _ -> putStrLn "Usage: runghc euler-204-generalised-hamming-numbers.hs <type> <limit>"
