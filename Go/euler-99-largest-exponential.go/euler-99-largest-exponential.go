// Package main is the entry point for the program.
package main

import (
	"bufio"   // Bufio provides buffering for input/output operations, which is used for efficiently reading lines from a file.
	"fmt"     // Fmt is used for formatted printing to the console, specifically used for error handling.
	"math"    // Math provides mathematical functions. In this program, it is used for logarithmic calculations.
	"os"      // Os is used to access the command line arguments and handle file operations, which for reading file input.
	"strconv" // Strconv is used to convert strings to integers, allowing the program to process numerical values from the input file.
	"strings" // Strings provides string manipulation functions. Here, it is used to split lines based on commas for parsing.
)

// main is the entry point of the program.
func main() {

	// Check if a command-line argument (filename) is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-99-largest-exponential.go <filename>")
		return
	}

	// Get the filename from the command-line argument
	filename := os.Args[1]

	// Open the .txt file
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close() // Ensure the file is closed at the end

	// Create a scanner to read the file line by line
	scanner := bufio.NewScanner(file)
	linenum := 0
	highestLine := 0
	highestTotal := 0.0

	// Iterate through each line in the file
	for scanner.Scan() {
		linenum++
		line := scanner.Text()
		base, exponent, err := split(line)
		if err != nil {
			fmt.Println("Error occurred, couldn't convert to integers:", err)
			return
		}

		// Calculate the total using logarithm
		total := calcTotal(base, exponent)

		// Compare the current line total to the highest line total
		if total > highestTotal {
			highestLine = linenum
			highestTotal = total
		}
	}
	printResult(highestLine)
}

// split splits the line by the comma, converts the values into int, and checks for errors.
func split(line string) (int, int, error) {
	// Split the input line by a comma to get individual values
	values := strings.Split(line, ",")

	// Check if the input line contains exactly two values: Base and exponent
	if len(values) != 2 {
		return 0, 0, fmt.Errorf("Invalid input: %s", line)
	}

	// Convert the values into integers
	base, error1 := strconv.Atoi(values[0])
	exponent, error2 := strconv.Atoi(values[1])

	// Check for errors during conversion
	if error1 != nil {
		return 0, 0, error1
	} else if error2 != nil {
		return 0, 0, error2
	} else {
		return base, exponent, nil
	}
}

// calcTotal calculates the total using logarithm.
func calcTotal(base, exponent int) float64 {
	return float64(exponent) * math.Log(float64(base)) // Using the power rule of logarithms.
}

// printResult prints the result based on the line number.
func printResult(line int) {
	if line == 0 {
		fmt.Println("No line has been found in the file.")
	} else {
		fmt.Println(line)
	}
}
