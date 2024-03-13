Euler 204: Square Remainders
===================================

This project aims to solve the Euler 204 problem (https://projecteuler.net/problem=204). The goal is to calculate how many Hamming numbers are there less than or equal to `s` of any given type `n`.

Project Structure
-----------------

- `euler-204-generalised-hamming-numbers.go` - The Go source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 191 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with two values as input or maybe not:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ g++ -o euler-204-generalised-hamming-numbers euler-204-generalised-hamming-numbers.cpp

$ ./euler-204-generalised-hamming-numbers 5 10000000d
Error: Both <type> and <limit> must be integers.

$ ./euler-204-generalised-hamming-numbers 5two 100000000
Error: Both <type> and <limit> must be integers.

$ ./euler-204-generalised-hamming-numbers 44
Usage: ./euler-204-generalised-hamming-numbers <type> <limit>

$ ./euler-204-generalised-hamming-numbers
Usage: ./euler-204-generalised-hamming-numbers <type> <limit>
