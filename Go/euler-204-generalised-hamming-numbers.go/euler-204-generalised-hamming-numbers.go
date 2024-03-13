package main

import (
	"fmt"     // Fmt is used to print a formatted string to the console
	"math"    // Math provides mathematical functions. In this program, it is used for logarithmic calculations.
	"os"      // Os is used to access the command line arguments and to terminate the program with a specified exit code, this is for error handling
	"strconv" // Strconv is used to convert a string to an integer from the command line
)

// factors represent the prime factors to be used in the combinations
var factors []int

// limit is the upper limit for the product in the combinations
var limit int

func main() {

	// Check if there are two values inputted
	if len(os.Args) != 3 {
		fmt.Println("Usage: go run euler-204-generalised-hamming-numbers.go <type> <limit>")
		return
	}

	// Prime Type
	primetype, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid type.\nError message: %v\n", err)
		return
	}

	// Limit
	limit, err = strconv.Atoi(os.Args[2])
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid limit.\nError message: %v\n", err)
		return
	}

	// Find prime factors up to the given limit
	for num := 1; num <= primetype; num++ {
		result := isPrimeNumber(num)
		if result {
			factors = append(factors, num)
		}
	}

	// Initialize the totalCount and calculate combinations starting from the first factor
	final := generalisedHammingNumbers(0, 1, 0)

	// Print the final count of combinations that satisfied the condition
	fmt.Println(final)
}

// isPrimeNumber checks if a given number is a prime number
func isPrimeNumber(number int) bool {
	if number < 2 {
		return false
	}
	squareRoot := int(math.Sqrt(float64(number)))
	for i := 2; i <= squareRoot; i++ {
		if number%i == 0 {
			return false
		}
	}
	return true
}

// generalisedHammingNumbers recursively computes the combinations of prime factors
// to find the count of generalised Hamming numbers within a specified limit
// Parameters:
//
//	index: current index in the prime factor array
//	product: current product of the prime factors in the combination
//	total: total count of combinations if satisfying the condition
func generalisedHammingNumbers(index, product, total int) int {
	// If the current product is within the limit, increment the total count
	if product <= limit {
		total++ // Increment the total count for valid combinations

		// Recursively calculate combinations for the remaining factors
		for j := index; j < len(factors); j++ {
			total = generalisedHammingNumbers(j, product*factors[j], total)
		}
	}

	return total
}
