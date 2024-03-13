package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

// isPrime checks if a given number is prime.
func isPrime(n int) bool {
	// If n is less than or equal to 1, it's not prime.
	if n <= 1 {
		return false
	}
	// 2 is the only even prime number.
	if n == 2 {
		return true
	}
	// If n is even and greater than 2, it's not prime.
	if n%2 == 0 {
		return false
	}

	// Calculate the square root of n to determine the maximum possible divisor.
	maxDivisor := int(math.Sqrt(float64(n)))

	// Check odd divisors starting from 3 up to the square root of n.
	for i := 3; i <= maxDivisor; i += 2 {
		if n%i == 0 {
			return false // n is divisible by i, so it's not prime.
		}
	}
	return true // n is prime.
}

// findNthPrime finds the nth prime number.
func findNthPrime(n int) int {
	count := 0 // Counter for the number of primes found.
	num := 1   // Starting from the first positive integer.

	// Loop until count reaches the desired value of n.
	for count < n {
		num++
		if isPrime(num) {
			count++ // Increment count when a prime number is found.
		}
	}
	return num // Return the nth prime number.
}

func main() {
	// Check if the required command-line argument is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-7-10001st-Prime.go <value_of_n>")
		return
	}

	// Parse the command-line argument
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input: Please enter a valid number.")
		fmt.Println("Error message:", err)
		return
	}

	result := findNthPrime(n)
	fmt.Println(result)
}
