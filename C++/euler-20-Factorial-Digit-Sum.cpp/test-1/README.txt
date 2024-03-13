Euler 20: Factorial Digit sum
===================================

This project aims to solve the Euler 20 problem (https://projecteuler.net/problem=20). The goal is to caluclate the sum of the digits of the factorial of 100

Project Structure
-----------------

- `euler-20-Factorial-Digit-Sum.cpp` - The C++ source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the provided value.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 109 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with values as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:
$ g++ -o euler-20-Factorial-Digit-Sum euler-20-Factorial-Digit-Sum.cpp
$ ./euler-20-Factorial-Digit-Sum 120
783
$ ./euler-20-Factorial-Digit-Sum five
Error: Invalid input. Please enter a valid number
$ ./euler-20-Factorial-Digit-Sum
Usage: ./euler-20-Factorial-Digit-Sum <value_of_n>

