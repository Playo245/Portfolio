import System.Environment (getArgs)

-- The main function of the program.
main :: IO ()
main = do
  -- Get command-line arguments
  args <- getArgs

  -- Check if two command-line arguments are provided
  case args of
    [first, last] -> do
      -- Attempt to parse the first and last arguments as integers
      case reads first of
        [(firstNum, "")] -> do
          case reads last of
            [(lastNum, "")] -> do
              -- Calculate the sum of maximum remainders for each 'a' in the specified range
              let sumResult = sum [maxR a | a <- [firstNum..lastNum]]
              -- Print the result to the console
              putStrLn $ show sumResult
            _ -> putStrLn "Error: Invalid second input."
        _ -> putStrLn "Error: Invalid first input."
    _ -> putStrLn "Usage: runghc euler-120-square-remainders.hs <first> <last>"

-- Function to find the maximum remainder for a given 'a'
maxR :: Int -> Int
maxR a = maximum [remainder n | n <- [1..2*a]]
  where
    -- Calculate the remainder for a given 'n'
    remainder n = (term1 + term2) `mod` (a * a)
      where
        term1 = numeric (a-1) n (a*a)  -- Calculate (a-1)^n
        term2 = numeric (a+1) n (a*a)  -- Calculate (a+1)^n

-- Function to calculate (base^exponent) % modulus efficiently
numeric :: Int -> Int -> Int -> Int
numeric base exponent modulus = go base exponent 1
  where
    -- Function for modular exponentiation using binary exponentiation algorithm
    go _ 0 result = result
    go base exponent result
      -- If the exponent is odd, multiply the result by the base and reduce the exponent by half
      | exponent `mod` 2 == 1 = go (base * base `mod` modulus) (exponent `div` 2) (result * base `mod` modulus)
      -- If the exponent is even, just reduce the exponent by half
      | otherwise = go (base * base `mod` modulus) (exponent `div` 2) result
