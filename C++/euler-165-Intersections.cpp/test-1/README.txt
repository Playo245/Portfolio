Euler 165: Intersections
===================================

This project aims to solve the Euler 165 problem (https://projecteuler.net/problem=165). The goal is to find How many distinct true intersection points are found among the 5000 line segment

Project Structure
-----------------

- `euler-165-Intersections.cpp` - The C++ source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the provided value.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 109 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with value as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ g++ -o euler-165-Intersections euler-165-Intersections.cpp

$ ./euler-165-Intersections 367
16274

$ ./euler-165-Intersections 45two
Error: Invalid input. Please enter a valid number

$ ./euler-165-Intersections twofifty
Error: Invalid input. Please enter a valid number

$ ./euler-165-Intersections
Usage: ./euler-165-Intersections <value_of_n>

