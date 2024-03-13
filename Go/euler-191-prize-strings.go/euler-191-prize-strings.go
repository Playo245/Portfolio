package main

import (
	"fmt"     // Fmt is used to print a formatted string to the console
	"os"      // Os is used to access the command line arguments and to terminate the program with a specified exit code, this is for error handling
	"strconv" // Strconv is used to convert a string to an integer from the command line
)

// Constants representing the number of days, absences, and being late
const (
	Absent = 2
	Late   = 1
)

// Entry point of the program
func main() {

	// Check if there are two values inputted
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-191-prize-strings.go <day>")
		return
	}

	days, err := strconv.Atoi(os.Args[1])
	// Error check...
	if err != nil {
		fmt.Printf("Invalid input: Please enter a valid day.\nError message: %v\n", err)
		return
	}

	var final int = findTotal(days) // Declaring variable "final" to store the result
	fmt.Printf("%d\n", final)       // Prints out the final result from the findTotal function
}

// Function to find the total amount of prize trinary strings found in the number of days given
func findTotal(Days int) int {

	// Initializing a 3D slice array to store results.
	// The dimensions are determined by variables: Days, Absent, and Late.
	// Since Days is not a constant variable due to testing, the array size is set to Days+1.
	// Each dimension represents different aspects of the data: days, absence, and lateness.
	PrizeList := make([][][]int, Days+1)
	for i := range PrizeList {
		PrizeList[i] = make([][]int, Absent+1)
		for j := range PrizeList[i] {
			PrizeList[i][j] = make([]int, Late+1)
		}
	}

	// Base case: There is one way to be present on day 0 with 0 instances of absence, being in, or being late
	PrizeList[0][0][0] = 1

	// Dynamic programming loop to fill in the array based on recurrence relations
	for i := 1; i <= Days; i++ {
		// Loop over instances of absence
		for x := 0; x <= Absent; x++ {
			// Loop over instances of lateness
			for y := 0; y <= Late; y++ {
				var sum int

				// If no instances of absence on the current day
				if x == 0 {
					sum = 0

					// Calculate the sum for being on time
					for z := 0; z <= Absent; z++ {
						sum += PrizeList[i-1][z][y] // On time
					}

					// If there are instances of being late on the previous day, calculate the sum for being late
					if y > 0 {
						for z := 0; z <= Absent; z++ {
							sum += PrizeList[i-1][z][y-1] // Late
						}
					}
				} else {
					// If there are instances of absence, consider the sum for being absent
					sum = PrizeList[i-1][x-1][y] // Absent
				}

				// Store the calculated sum in the array
				PrizeList[i][x][y] = sum
			}
		}
	}

	// Calculate the total by summing up all the possibilities for the last day
	var total int
	for x := 0; x <= Absent; x++ {
		for y := 0; y <= Late; y++ {
			total += PrizeList[Days][x][y]
		}
	}

	// Return the total number of possibilities
	return total
}
