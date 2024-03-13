#include <iostream>
#include <sstream>
#include <cmath>

// isPrime checks if a given number is prime.
bool isPrime(int n) {
    // If n is less than or equal to 1, it's not prime.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // If n is even and greater than 2, it's not prime.
    if (n % 2 == 0) {
        return false;
    }

    // Calculate the square root of n to determine the maximum possible divisor.
    int maxDivisor = static_cast<int>(std::sqrt(static_cast<double>(n)));

    // Check odd divisors starting from 3 up to the square root of n.
    for (int i = 3; i <= maxDivisor; i += 2) {
        if (n % i == 0) {
            return false; // n is divisible by i, so it's not prime.
        }
    }
    return true; // n is prime.
}

// findNthPrime finds the nth prime number.
int findNthPrime(int n) {
    int count = 0; // Counter for the number of primes found.
    int num = 1;   // Starting from the first positive integer.

    // Loop until count reaches the desired value of n.
    while (count < n) {
        num++;
        if (isPrime(num)) {
            count++; // Increment count when a prime number is found.
        }
    }
    return num; // Return the nth prime number.
}

int main(int argc, char* argv[]) {
    // Check if the required command-line argument is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-7-10001st-Prime <value_of_n>" << std::endl;
        return 0;
    }

    // Parse the command-line argument
    int n;
    std::istringstream input(argv[1]);
    if (!(input >> n) || !input.eof()) {
        std::cout << "Error: Invalid input. Please enter a valid integer." << std::endl;
        return 0;
    }

    int result = findNthPrime(n);
    std::cout << result << std::endl;

    return 0;
}
