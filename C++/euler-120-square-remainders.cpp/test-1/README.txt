Euler 120: Square Remainders
===================================

This project aims to solve the Euler 120 problem (https://projecteuler.net/problem=120). The goal is to find the sum of the maximum remainders for a given range.

Project Structure
-----------------

- `euler-120-square-remainders.cpp` - The Go source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 120 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with two values as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ g++ -o euler-120-square-remainders euler-120-square-remainders.cpp

$ ./euler-120-square-remainders 2 9
222

$ ./euler-120-square-remainders 16 56
56644

$ ./euler-120-square-remainders 3two 98
Error: Both <first> and <last> must be integers.

$ ./euler-120-square-remainders 53 4two3
Error: Both <first> and <last> must be integers.

$ ./euler-120-square-remainders 62
Usage: ./euler-120-square-remainders <first> <last>

$ ./euler-120-square-remainders
Usage: ./euler-120-square-remainders <first> <last>
