Euler 204: Square Remainders
===================================

This project aims to solve the Euler 204 problem (https://projecteuler.net/problem=204). The goal is to calculate how many Hamming numbers are there less than or equal to `s` of any given type `n`.

Project Structure
-----------------

- `euler-204-generalised-hamming-numbers.hs` - The Haskell source code for solving the problem.
- `runner.zsh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 191 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.zsh script is executable:

2. Run the runner.zsh script to execute the script with two values as input or maybe not:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ runghc euler-204-generalised-hamming-numbers.hs 5 10000000d
Error: Invalid second input.

$ runghc euler-204-generalised-hamming-numbers.hs 5two 100000000
Error: Invalid first input.

$ runghc euler-204-generalised-hamming-numbers.hs 44
Usage: runghc euler-204-generalised-hamming-numbers.hs <type> <limit>

$ runghc euler-204-generalised-hamming-numbers.hs
Usage: runghc euler-204-generalised-hamming-numbers.hs <type> <limit>
