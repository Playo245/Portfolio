#include <iostream>   // Input and output stream handling (for std::cout and std::endl)
#include <cmath>      // Math functions like sqrt used in isPrimeNumber function
#include <vector>     // Dynamic array for storing prime factors in the HammingNumbers class
#include <cstdint>    // Standard integer types for fixed-size integers, used for int64_t as integers have larger values in hammingNumbers

class HammingNumbers {
private:
    std::vector<int> factors;  // Stores prime factors up to the given limit
    int limit;  // The limit up to which Hamming numbers are calculated

public:
    HammingNumbers() {}

    // Method to initiate the calculation of Hamming numbers
    void run(int primetype, int limit) {
        this->limit = limit;

        // Find prime factors up to the given limit
        for (int num = 1; num <= primetype; num++) {
            if (isPrimeNumber(num)) {
                factors.push_back(num);
            }
        }

        // Initialize the totalCount and calculate combinations starting from the first factor
        int64_t finalCount = hammingNumbers(0, 1, 0);

        // Print the final count of combinations that satisfied the condition
        std::cout << finalCount << std::endl;
    }

private:
    // Function to check if a number is prime
    bool isPrimeNumber(int number) {
        if (number < 2) {
            return false;
        }
        int squareRoot = static_cast<int>(std::sqrt(static_cast<double>(number)));
        for (int i = 2; i <= squareRoot; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to calculate Hamming numbers
    int64_t hammingNumbers(int index, int64_t product, int64_t total) {
        // If the current product is within the limit, increment the total count
        if (product <= limit) {
            total++; // Increment the total count for valid combinations

            // Recursively calculate combinations for the remaining factors
            for (int j = index; j < factors.size(); j++) {
                total = hammingNumbers(j, product * factors[j], total);
            }
        }

        return total;
    }
};

int main(int argc, char *argv[]) {
    // Check if there are two values inputted
    if (argc != 3) {
        std::cout << "Usage: ./euler-204-generalised-hamming-numbers <type> <limit>" << std::endl;
        return 0;
    }

    char* endptr1;
    char* endptr2;

    // Convert command line arguments to integers
    int primetype = std::strtol(argv[1], &endptr1, 10);
    int limit = std::strtol(argv[2], &endptr2, 10);

    // Check if the conversion was successful
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        std::cout << "Error: Both <type> and <limit> must be integers." << std::endl;
        return 0;
    }

    // Create an instance of HammingNumbers
    HammingNumbers numbers;

    // Run the calculation
    numbers.run(primetype, limit);

    return 0;
}
