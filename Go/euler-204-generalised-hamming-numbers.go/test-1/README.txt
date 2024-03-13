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

$ go run euler-204-generalised-hamming-numbers.go 5 10000000d
Invalid input: Please enter a valid limit.
Error message: strconv.Atoi: parsing "10000000d": invalid syntax

$ go run euler-204-generalised-hamming-numbers.go 5two 100000000
Invalid input: Please enter a valid type.
Error message: strconv.Atoi: parsing "5two": invalid syntax

$ go run euler-204-generalised-hamming-numbers.go 44
Usage: go run euler-204-generalised-hamming-numbers.go <type> <limit>

$ go run euler-204-generalised-hamming-numbers.go
Usage: go run euler-204-generalised-hamming-numbers.go <type> <limit>
