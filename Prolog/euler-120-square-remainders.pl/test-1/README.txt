Euler 120: Square Remainders
===================================

This project aims to solve the Euler 120 problem (https://projecteuler.net/problem=120). The goal is to find the sum of the maximum remainders for a given range.

Project Structure
-----------------

- `euler-120-square-remainders.pl` - The Prolog source code for solving the problem.
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

$ swipl -s euler-120-square-remainders.pl -- 3 5
34

$ swipl -s euler-120-square-remainders.pl -- 7 11
352

$ swipl -s euler-120-square-remainders.pl -- 2 43
26028

$ swipl -s euler-120-square-remainders.pl -- 9 78
156450

$ swipl -s euler-120-square-remainders.pl -- 6 223
3683982

$ swipl -s euler-120-square-remainders.pl -- 7 785
161091166
