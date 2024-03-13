Euler 120: Square Remainders
===================================

This project aims to solve the Euler 120 problem (https://projecteuler.net/problem=120). The goal is to find the sum of the maximum remainders for a given range.

Project Structure
-----------------

- `euler-120-square-remainders.go` - The Go source code for solving the problem.
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

$ go run euler-120-square-remainders.go 2 9
222

$ go run euler-120-square-remainders.go 16 56
56644

$ go run euler-120-square-remainders.go 3two 98
Invalid input: Please enter a valid first number.
Error message: strconv.Atoi: parsing "3two": invalid syntax

$ go run euler-120-square-remainders.go 53 4two3
Invalid input: Please enter a valid last number.
Error message: strconv.Atoi: parsing "4two3": invalid syntax

$ go run euler-120-square-remainders.go 62
Usage: go run euler-120-square-remainders.go <first> <last>.

$ go run euler-120-square-remainders.go
Usage: go run euler-120-square-remainders.go <first> <last>.
