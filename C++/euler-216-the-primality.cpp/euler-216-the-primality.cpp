#include <iostream>   // Input and output stream handling (for std::cout and std::endl)
#include <vector>     // Dynamic array for storing prime factors in the HammingNumbers class
#include <cstdint>    // Standard integer types for fixed-size integers, used for int64_t as integers have larger values in hammingNumbers

// Class to handle primality calculations
class Primality {
private:
    std::vector<long long> sequence;  // Sequence of terms
    int totalCount;                   // Total count of prime terms found

    // Function to perform factorization in the positive direction
    void divideOutFactorsPositive(int currentTerm, int i, int limit) {
        for (int j = i + currentTerm; j <= limit; j += currentTerm) {
            // Continue dividing out factors until the currentTerm is no longer a factor
            while (sequence[j] % currentTerm == 0) {
                sequence[j] /= currentTerm;
            }
        }
    }

    // Function to perform factorization in the negative direction
    void divideOutFactorsNegative(int currentTerm, int i, int limit) {
        for (int j = i + (currentTerm - i) * 2 % currentTerm; j <= limit; j += currentTerm) {
            // Continue dividing out factors until the currentTerm is no longer a factor
            while (sequence[j] % currentTerm == 0) {
                sequence[j] /= currentTerm;
            }
        }
    }

    // Function to generate a sequence of terms based on a given limit
    void genSequence(int limit) {
        sequence.resize(limit + 1);

        // Populate the sequence using a specific formula
        for (int i = 2; i <= limit; ++i) {
            sequence[i] = 2LL * i * i - 1;
        }

        // Set initial terms to -1
        sequence[0] = sequence[1] = -1;
    }

public:
    // Constructor to initialize totalCount
    Primality() : totalCount(0) {}

    // Function to check primality of terms and update totalCount
    int primality(int limit) {
        // Generate the sequence of terms
        genSequence(limit);

        // Iterate through the sequence and check for primality
        for (int i = 2; i <= limit; ++i) {
            // Check if the term is prime using a specific formula
            if (sequence[i] == 2LL * i * i - 1) {
                totalCount++;
            }

            // If the term is within the limit, perform factorization
            if (sequence[i] <= limit * 2 && sequence[i] > 1) {
                int currentTerm = sequence[i];

                // Divide out factors in the positive direction
                divideOutFactorsPositive(currentTerm, i, limit);
                // Divide out factors in the negative direction
                divideOutFactorsNegative(currentTerm, i, limit);
            }
        }

        return totalCount;
    }
};

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-216-the-primality <limit>" << std::endl;
        return 0;
    }

    char* endptr;


    // Convert command line arguments to integers
    int limit = std::strtol(argv[1], &endptr, 10);

    // Check if the conversion was successful
    if (*endptr != '\0') {
        std::cout << "Error: <limit> must be integers." << std::endl;
        return 0;
    }

    // Create an instance of the Primality class
    Primality primality;

    // Call the primality function and print the result
    int final = primality.primality(limit);
    std::cout << final << std::endl;

    return 0;
}
