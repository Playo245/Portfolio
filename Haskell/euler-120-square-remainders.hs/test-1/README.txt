Euler 120: Square Remainders
===================================

This project aims to solve the Euler 120 problem (https://projecteuler.net/problem=120). The goal is to find the sum of the maximum remainders for a given range.

Project Structure
-----------------

- `euler-120-square-remainders.hs` - The Haskell source code for solving the problem.
- `runner.zsh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 120 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.zsh script is executable:

2. Run the runner.zsh script to execute the script with two values as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ runghc euler-120-square-remainders.hs 2 9
222

$ runghc euler-120-square-remainders.hs 16 56
56644

$ runghc euler-120-square-remainders.hs 3two 98
Error: Invalid first input.

$ runghc euler-120-square-remainders.hs 53 4two3
Error: Invalid second input.

$ runghc euler-120-square-remainders.hs 62
Usage: runghc euler-120-square-remainders.hs <first> <last>

$ runghc euler-120-square-remainders.hs
Usage: runghc euler-120-square-remainders.hs <first> <last>
