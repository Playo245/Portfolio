Euler 109: Darts
===================================

This project aims to solve the Euler 109 problem (https://projecteuler.net/problem=109). The goal is to calculate how many distinct ways can a player checkout with a score less than 100?

Project Structure
-----------------

- `euler-109-Darts.cpp` - The C++ source code for solving the problem.
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

$ g++ -o euler-109-Darts euler-109-Darts.cpp

$ ./euler-109-Darts 150
42295

$ ./euler-109-Darts two3
Error: Invalid input. Please enter a valid number

$ ./euler-109-Darts ten
Error: Invalid input. Please enter a valid number

$ ./euler-109-Darts
Usage: ./euler-109-Darts <value_of_n>

