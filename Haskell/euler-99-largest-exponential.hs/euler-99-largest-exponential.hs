import System.Environment (getArgs)     -- For getting command-line arguments
import System.Directory (doesFileExist) -- For checking if a file exists
import Text.Read (readMaybe)            -- For safely reading values from strings


-- The main function of the program.
main :: IO ()
main = do
  -- Get command-line arguments
  args <- getArgs

  -- Check if a filename is provided as a command-line argument
  case args of
    -- If a single filename is provided
    [filename] -> do
      -- Check if the file exists
      fileExists <- doesFileExist filename
      if fileExists
        then do
          -- Read the file content
          fileContent <- readFile filename

          -- Process the lines and find the line number with the highest total
          let result = foldl findLine (Right (0, 0)) (zip [1..] (lines fileContent))

          -- Print the result or error message
          case result of
            -- If the result is successful, print the line number with the highest total
            Right (highestLine, _) -> printResult highestLine
            -- If there is an error, print the error message
            Left err -> putStrLn err
        else
          putStrLn $ "Error: File '" ++ filename ++ "' does not exist."

    -- If the number of command-line arguments is not equal to 1, print a usage message
    _ -> putStrLn "Usage: runghc euler-99-largest-exponential.hs <filename>"



-- Finds the line with the highest total and its line number. It takes an heap and a tuple containing the current line number and line content.
findLine :: Either String (Int, Double) -> (Int, String) -> Either String (Int, Double)
-- If an error has occurred in the heap, skip further all lines and return the error.
findLine heap@(Left _) _ = heap
-- If the heap is a successful result and contains (line number, highest total), 
-- process the current line and update the heap if the numeric value of the current line is higher then the heap.
findLine (Right (linenum, highestTotal)) (currentLine, line) = do
  -- Split the line and handle errors using the split function.
  let splitResult = split line

  -- Calculate the total using logarithm if the split is successful.
  case splitResult of
    Right (base, exponent) ->
      let total = findTotal base exponent
      in if total > highestTotal
           -- If the calculated total is higher than the current highest total, update the heap to the current line number and total.
           -- Otherwise, keep the existing heap values.
           then Right (currentLine, total)
           else Right (linenum, highestTotal)
    -- If there is an error in splitting the line, return the error.
    Left err -> Left err


-- Splits the line by a comma, converts values to integers, and checks for errors.
split :: String -> Either String (Int, Int)
split line =
  -- Use the map comma function to replace commas with spaces, then use words to split the line into a list of words
  case mapM readMaybe (words (map comma line)) of
    -- If the conversion of the list of words to integers is successful and results in a list [base, exponent], then return a Right containing a tuple (base, exponent).
    -- If there is an error in conversion or the list does not have exactly two elements, return a Left containing an error message.
    Just [base, exponent] -> Right (base, exponent)
    _ -> Left ("Invalid line: " ++ line)

-- findTotal takes two integer arguments: base and exponent
findTotal :: Int -> Int -> Double
findTotal base exponent =
  -- Convert the exponent to a Double and multiply it by the logarithm of the base and result is a Double
  fromIntegral exponent * log (fromIntegral base)


-- Replaces commas with spaces for integer separation.
comma :: Char -> Char
comma ',' = ' '
comma c = c

-- Prints the result based on the line number.
printResult :: Int -> IO ()
printResult line =
  if line == 0
    -- If the line number is 0, it means no line has been found, Therefore printing the message below.
    -- If the line number is not 0, it means a line has been found, Therefore printing the line with the highest numeric value.
    then putStrLn "No line has been found in the file."
    else print line
