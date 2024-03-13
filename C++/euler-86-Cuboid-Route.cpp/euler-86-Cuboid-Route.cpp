#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

// isInteger checks if a given double value is an integer
bool isInteger(double value) {
    return value == std::trunc(value);
}

// isStringInteger checks if a given string represents a valid integer
bool isStringInteger(const std::string& s) {
    size_t pos;
    try {
        std::stoi(s, &pos);
    } catch (const std::invalid_argument& e) {
        return false; // stoi() threw an invalid_argument exception, indicating a non-integer
    } catch (const std::out_of_range& e) {
        return false; // stoi() threw an out_of_range exception, indicating an out-of-range integer
    }
    return pos == s.length(); // Ensure the entire string is consumed
}

int main(int argc, char* argv[]) {
    // Check if the required command-line argument is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-86-Cuboid-Route <value_of_n>" << std::endl;
        return 0;
    }

    // Parse the command-line argument
    std::string inputString = argv[1];
    if (!isStringInteger(inputString) || inputString.find('.') != std::string::npos) {
        std::cout << "Error: Invalid input. Please enter a valid integer." << std::endl;
        return 0;
    }

    int targetSolutions = std::stoi(inputString);
    if (targetSolutions <= 0) {
        std::cout << "Error: Invalid input. Please enter a valid positive integer." << std::endl;
        return 0;
    }

    int solutionCount = 0; // loop until this reaches the target
    int minimumM = 0;      // store the answer

    // Outer loop (a)
    for (int m = 1; solutionCount < targetSolutions; ++m) {
        // Middle loop (b)
        for (int j = 1; j < m + 1; ++j) {
            // Inner loop (c)
            for (int k = 1; k < j + 1; ++k) {
                // Calculate the shortest path using Pythagoras theorem
                double distance = std::sqrt(static_cast<double>((m * m) + ((j + k) * (j + k))));

                // Check if the shortest path is an integer and not a float
                if (isInteger(distance)) {
                    ++solutionCount; // Increment the count of solutions
                    minimumM = m;     // Store the value of M as the answer
                }
            }
        }
    }

    // Print the final answer
    std::cout << minimumM << std::endl;

    return 0;
}
