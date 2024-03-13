Euler 7: 10001st Prime
===================================

This project aims to solve the Euler 7 problem (https://projecteuler.net/problem=7). The goal is to find the 10001st prime

Project Structure
-----------------

- `euler-7-10001st-Prime.cpp` - The C++ source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the provided value.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 109 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with two values as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ g++ -o euler-7-10001st-Prime euler-7-10001st-Prime.cpp

$ ./euler-7-10001st-Prime 10002
104759

$ ./euler-7-10001st-Prime 6seven
Error: Invalid input. Please enter a valid integer.

$ ./euler-7-10001st-Prime eight
Error: Invalid input. Please enter a valid integer.

$ ./euler-7-10001st-Prime
Usage: ./euler-7-10001st-Prime <value_of_n>


