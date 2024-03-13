#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Class definition for handling large integers
class BigInt {
public:
    // Constructor to initialize the BigInt with an integer value
    BigInt(int value = 0) {
        // Convert the integer value into individual digits and store them in reverse order
        while (value > 0) {
            digits.push_back(value % 10);
            value /= 10;
        }
    }

    // Function to multiply the BigInt by an integer multiplier
    void multiply(int multiplier) {
        int carry = 0;
        // Perform multiplication digit by digit
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == digits.size()) {
                digits.push_back(0);
            }
            long long current = carry + digits[i] * 1ll * multiplier;
            digits[i] = current % 10;
            carry = current / 10;
        }
        // Remove leading zeros to maintain the invariant
        removeLeadingZeros();
    }

    // Function to calculate the sum of digits in the BigInt
    int sumDigits() const {
        int sum = 0;
        for (int digit : digits) {
            sum += digit;
        }
        return sum;
    }

    // Overloaded stream insertion operator to print the BigInt
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

private:
    std::vector<int> digits; // Vector to store individual digits

    // Helper function to remove leading zeros
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }
};

// Function to calculate the factorial of an integer
BigInt factorial(int n) {
    BigInt result = 1;
    for (int i = 2; i <= n; ++i) {
        result.multiply(i);
    }
    return result;
}

int main(int argc, char** argv) {
    // Check if the required command-line argument is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-20-Factorial-Digit-Sum <value_of_n>" << std::endl;
        return 0;
    }

    // Parse the command-line argument
    char* endptr;
    int n = std::strtol(argv[1], &endptr, 10);

    // Check for input errors
    if (*endptr != '\0' || n < 0) {
        std::cout << "Error: Invalid input. Please enter a valid number" << std::endl;
        return 0;
    }

    // Calculate the factorial of the input and print the sum of its digits
    BigInt result = factorial(n);
    int sum = result.sumDigits();
    std::cout << sum << std::endl;

    return 0;
}
