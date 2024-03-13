#include <iostream>    // Input and output stream handling
#include <cstdlib>     // General purpose C library functions, used for atoi (string to integer conversion)
#include <cstdint>     // Integer types with specified widths

// The MaxR class is designed to find and calculate the sum of maximum remainders
// for a given range of 'a' values, as specified by the Euler Project problem.

class MaxR {
private:
    int first;    // First value in the range
    int last;     // Last value in the range

    // Function to calculate (base^exponent) % modulus efficiently
    int64_t numeric(int64_t base, int64_t exponent, int64_t modulus) {
        int64_t result = 1;
        base = base % modulus; // Take modulus of base to handle potential overflow

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
            exponent /= 2;
        }
        return result;
    }

public:
    // Constructor to initialize the first and last values in the range
    MaxR(int start, int end) : first(start), last(end) {}

    // Function to find the maximum remainder for a given 'a' value
    int maxRemainder(int a) {
        int maxR = 0;
        // Iterate through a range of 'n' values to find the maximum remainder
        for (int n = 1; n <= 2 * a; ++n) {
            int64_t term1 = numeric(a - 1, n, a * a);
            int64_t term2 = numeric(a + 1, n, a * a);
            int remainder = static_cast<int>((term1 + term2) % (a * a));

            // Update maxR if the current remainder is greater
            if (remainder > maxR) {
                maxR = remainder;
            }
        }
        return maxR;
    }

    // Function to calculate the sum of maximum remainders for the given range
    int result() {
        int sum = 0;
        // Iterate through the range of 'a' values and accumulate the maximum remainders
        for (int a = first; a <= last; ++a) {
            sum += maxRemainder(a);
        }
        return sum;
    }
};

// The main function is the entry point of the program
int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 3) {
        std::cout << "Usage: ./euler-120-square-remainders <first> <last>\n";
        return 0;
    }

    char* endptr1;
    char* endptr2;

    int first = std::strtol(argv[1], &endptr1, 10);
    int last = std::strtol(argv[2], &endptr2, 10);

    // Check if the conversion was successful
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        std::cout << "Error: Both <first> and <last> must be integers.\n";
        return 0;
    }

    // Create an instance of the MaxR class with the specified range
    MaxR find(first, last);
    // Calculate and display the result, which is the sum of maximum remainders
    int result = find.result();
    std::cout << result << std::endl;

    return 0;
}
