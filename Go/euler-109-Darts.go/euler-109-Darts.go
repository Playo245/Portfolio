package main

import (
	"fmt"
	"os"
	"strconv"
)

// countCheckOuts calculates the number of possible checkouts given a range of starting and ending indices
func countCheckOuts(landings []int, start, end, upperBound int) int {
	nCheckOuts := 0
	// Outer loop iterates over the possible starting positions
	for i := start; i <= end; i++ {
		sum := landings[i]

		// Check if the sum is below the upper bound and increment the count
		if sum < upperBound {
			nCheckOuts++
		}

		// Middle loop represents the second dart
		for j := 0; j < len(landings); j++ {
			secondDart := landings[j]
			sum += secondDart

			// Check if the sum is below the upper bound and increment the count
			if sum < upperBound {
				nCheckOuts++
			}

			// Inner loop represents the third dart
			for k := j; k < len(landings); k++ {
				thirdDart := landings[k]
				sum += thirdDart

				// Check if the sum is below the upper bound and increment the count
				if sum < upperBound {
					nCheckOuts++
				}

				sum -= thirdDart // Reset the sum for the next iteration
			}

			sum -= secondDart // Reset the sum for the next iteration
		}
	}
	return nCheckOuts
}

func main() {
	var landings []int

	// Push in doubles.
	for i := 1; i <= 20; i++ {
		landings = append(landings, 2*i)
	}
	landings = append(landings, 2*25)

	// Push in singles.
	for i := 1; i <= 20; i++ {
		landings = append(landings, i)
	}
	landings = append(landings, 25)

	// Push in trebles.
	for i := 1; i <= 20; i++ {
		landings = append(landings, 3*i)
	}

	// Check if the required command-line argument is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-109-Darts.go <value_of_n>")
		return
	}

	// Parse the command-line argument
	upperBound, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input: Please enter a valid number.")
		fmt.Println("Error message:", err)
		return
	}

	// Count the number of possible checkouts and output the result
	nCheckOuts := countCheckOuts(landings, 0, 20, upperBound)
	fmt.Println(nCheckOuts)
}
