package main

// Importing necessary packages
import (
	"fmt"     // Provides formatted I/O functions
	"os"      // Provides a way to interact with the operating system, including command-line arguments
	"strconv" // Provides functions for string to integer conversion
)

var totalCount = 0

// primality function checks the primality of certain terms in a sequence
// and updates the totalCount of prime terms found.
func primality(limit int) int {
	// Generate the sequence of terms
	sequence := generateSequence(limit)

	// Iterate through the sequence and check for primality
	for i, term := range sequence {
		// Skip the first two terms as they are set to -1
		if i < 2 {
			continue
		}

		// Check if the term is prime using a specific formula
		if term == int64(2*i*i-1) {
			totalCount++
		}

		// If the term is within the limit, perform factorization
		if term <= int64(limit*2) && 1 < term {
			currentTerm := term

			// Divide out factors in the positive direction
			divideOutFactors(sequence, currentTerm, i, limit)
			// Divide out factors in the negative direction
			divideOutFactorsNegative(sequence, currentTerm, i, limit)
		}
	}

	return totalCount
}

// divideOutFactors performs factorization in the positive direction
func divideOutFactors(sequence []int64, currentTerm int64, i, limit int) {
	term := int(currentTerm)

	// Iterate through the sequence and divide out factors
	for j := i + term; j <= limit; j += term {
		// Continue dividing out factors until the currentTerm is no longer a factor
		for sequence[j]%currentTerm == 0 {
			sequence[j] /= currentTerm
		}
	}
}

// divideOutFactorsNegative performs factorization in the negative direction
func divideOutFactorsNegative(sequence []int64, currentTerm int64, i, limit int) {
	term := int(currentTerm)

	// Iterate through the sequence and divide out factors in the negative direction
	for j := i + (term-i)*2%term; j <= limit; j += term {
		// Continue dividing out factors until the currentTerm is no longer a factor
		for sequence[j]%currentTerm == 0 {
			sequence[j] /= currentTerm
		}
	}
}

// generateSequence generates a sequence of terms based on a given limit
func generateSequence(limit int) []int64 {
	sequence := make([]int64, limit+1)

	// Populate the sequence using a specific formula
	for i := 2; i <= limit; i++ {
		sequence[i] = int64(2*i*i - 1)
	}

	// Set initial terms to -1
	sequence[0], sequence[1] = -1, -1

	return sequence
}

func main() {
	// Check if the correct number of command-line arguments is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-216-the-primality.go <limit>")
		return
	}

	// Parse the limit from the command-line argument
	limit, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid limit.\nError message: %v\n", err)
		return
	}

	// Call the primality function and print the result
	final := primality(limit)
	fmt.Println(final)
}
