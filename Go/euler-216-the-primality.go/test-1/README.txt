Euler 216: Square Remainders
===================================

This project aims to solve the Euler 216 problem (https://projecteuler.net/problem=216). The goal is to find how many primes there are formed with t(n) = (2n^n) - 1
while n > 1.
Project Structure
-----------------

- `euler-216-the-primality.go` - The Go source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 191 problem.
- `stdout.txt` - An example output file containing the expected output from the program.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with one value as input or maybe not:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ go run euler-216-the-primality.go 10000
2202

$ go run euler-216-the-primality.go 50000
9175

$ go run euler-216-the-primality.go 50million
Invalid input: Please enter a valid limit.
Error message: strconv.Atoi: parsing "50million": invalid syntax

$ go run euler-216-the-primality.go
Usage: go run euler-216-the-primality.go <limit>
