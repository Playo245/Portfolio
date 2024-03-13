Euler 99: Largest Exponential
===================================

This project aims to solve the Euler 99 problem (https://projecteuler.net/problem=99). The goal is to find the line with the largest exponential in a 1000-line document named "numbers.txt".

Project Structure
-----------------

- `euler-99-largest-exponential.hs` - The Haskell source code for solving the problem.
- `runner.zsh` - The shell script to compile and run the program with the provided numbers.txt file.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 99 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.zsh script is executable:

2. Run the runner.zsh script to execute the script with the numbers.txt file as input:

Expected Output
---------------

After running the program, the expected output should be:

$ runghc euler-99-largest-exponential.hs numbers.txt
Invalid line: 189664,56940d
