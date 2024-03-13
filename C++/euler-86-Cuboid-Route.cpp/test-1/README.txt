Euler 86: Cuboid Route
===================================

This project aims to solve the Euler 86 problem (https://projecteuler.net/problem=86).

Project Structure
-----------------

- `euler-86-Cuboid-Route.cpp` - The C++ source code for solving the problem.
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

$ g++ -o euler-86-Cuboid-Route euler-86-Cuboid-Route.cpp

$ ./euler-86-Cuboid-Route 456
48

$ ./euler-86-Cuboid-Route 54two
Error: Invalid input. Please enter a valid integer.

$ ./euler-86-Cuboid-Route
Usage: ./euler-86-Cuboid-Route <value_of_n>


