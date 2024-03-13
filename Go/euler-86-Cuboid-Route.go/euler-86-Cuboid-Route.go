package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

// isInteger checks if a given float64 value is an integer
func isInteger(value float64) bool {
	return value == math.Trunc(value)
}

func main() {
	// Check if the required command-line argument is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-86-Cuboid-Route.go <value_of_n>")
		return
	}

	// Parse the command-line argument
	targetSolutions, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input: Please enter a valid number.")
		fmt.Println("Error message:", err)
		return
	}

	solutionCount := 0 // loop until this reached the target
	minimumM := 0      // store the answer

	// Outer loop (a)
	for m := 1; solutionCount < targetSolutions; m++ {
		// Middle loop (b)
		for j := 1; j < m+1; j++ {
			// Inner loop (c)
			for k := 1; k < j+1; k++ {
				// Calculate the shortest path using Pythagoras theorem
				distance := math.Sqrt(float64((m * m) + ((j + k) * (j + k))))

				// Check if the shortest path is an integer and not a float
				if isInteger(distance) {
					solutionCount++ // Increment the count of solutions
					minimumM = m    // Store the value of M as the answer
				}
			}
		}
	}

	// Print the final answer
	fmt.Println(minimumM)
}
