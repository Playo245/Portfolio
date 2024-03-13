package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

// factorial calculates the factorial of a given number n.
func factorial(n int) *big.Int {
	result := big.NewInt(1)
	for i := 1; i <= n; i++ {
		result.Mul(result, big.NewInt(int64(i)))
	}
	return result
}

// sumDigits calculates the sum of the digits of a big.Int number.
func sumDigits(num *big.Int) int {
	sum := 0
	for _, digit := range num.String() {
		sum += int(digit - '0')
	}
	return sum
}

func main() {
	// Check if the required command-line argument is provided
	if len(os.Args) != 2 {
		fmt.Println("Usage: go run euler-20-Factorial-Digit-Sum.go <value_of_n>")
		return
	}

	// Parse the command-line argument
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input: Please enter a valid number.")
		fmt.Println("Error message:", err)
		return
	}

	// Calculate the factorial of n
	result := factorial(n)

	// Output only the sum of the digits
	sum := sumDigits(result)
	fmt.Println(sum)
}
