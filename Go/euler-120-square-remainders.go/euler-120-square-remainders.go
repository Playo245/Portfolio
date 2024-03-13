package main

import (
	"fmt"     // Fmt is used to print a formatted string to the console
	"os"      // Os is used to access the command line arguments and to terminate the program with a specified exit code, this is for error handling
	"strconv" // Strconv is used to convert a string to an integer from the command line
)

func main() {

	// Check if there are two values inputted
	if len(os.Args) != 3 {
		fmt.Println("Usage: go run euler-120-square-remainders.go <first> <last>")
		return
	}

	// Initialize the sum variable to store the final result
	sum := 0

	// Define the range of values for 'a'
	first, err := strconv.Atoi(os.Args[1])
	// Error check....
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid first number.\nError message: %v\n", err)
		return
	}
	last, err := strconv.Atoi(os.Args[2])
	// Error check....
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid last number.\nError message: %v\n", err)
		return
	}

	// Iterate through values of 'a' from 'first' to 'last'
	for a := first; a <= last; a++ {
		// Calculate the maximum remainder for the current 'a' and add it to the sum
		remainder := maxR(a)
		sum += remainder
	}

	// Print the sum of the maximum remainders
	fmt.Printf("%d\n", sum)
}

// Function to find the maximum remainder for a given 'a'
func maxR(a int) int {
	maxR := 0

	// Iterate through possible values of 'n' up to 2a due to the fact 'n' varies, so does the max remainder
	for n := 1; n <= 2*a; n++ {
		// Calculate the terms using a more accurate approach
		term1 := numeric(a-1, n, a*a) // (a-1)^n
		term2 := numeric(a+1, n, a*a) // (a+1)^n

		// Calculate the remainder when (a-1)^n + (a+1)^n is divided by a^2
		remainder := (term1 + term2) % (a * a)

		// Update maxR if the current remainder is greater
		if remainder > maxR {
			maxR = remainder
		}
	}

	return maxR
}

// Function to calculate (base^exponent) % modulus efficiently
func numeric(base, exponent, modulus int) int {
	result := 1 // Initialize result to 1

	// Use modular exponentiation to efficiently calculate (base^exponent) % modulus
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % modulus
		}

		base = (base * base) % modulus
		exponent /= 2
	}

	return result
}
