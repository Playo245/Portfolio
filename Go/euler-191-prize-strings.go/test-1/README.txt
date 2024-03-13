Euler 191: Square Remainders
===================================

This project aims to solve the Euler 191 problem (https://projecteuler.net/problem=191). The goal is to find the sum of prize strings on a given day period which is called `n`.

Project Structure
-----------------

- `euler-191-prize-strings.go` - The Go source code for solving the problem.
- `runner.sh` - The shell script to compile and run the program with the two provided values.
- `task-description.ascii` - The asciidoc formatted task description for the Euler 191 problem.
- `stdout.txt` - An example output file containing the expected output from the program.
- `suppress-io.txt` - Hide the output in the Einstein report this ensures that students cannot hardwire the test cases into their solution.

Building and Running the Project
--------------------------------

1. Make sure the runner.sh script is executable:

2. Run the runner.sh script to execute the script with one value as input:

Expected Output
---------------

After running the program, the expected output for each cycle should be:

$ go run euler-191-prize-strings.go 3
19

$ go run euler-191-prize-strings.go 7
418

$ go run euler-191-prize-strings.go 11
7077

$ go run euler-191-prize-strings.go twenty
Invalid input: Please enter a valid day.
Error message: strconv.Atoi: parsing "twenty": invalid syntax

$ go run euler-191-prize-strings.go
Usage: go run euler-191-prize-strings.go <day>.
