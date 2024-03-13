#include <iostream>
#include <vector>
#include <cstdlib>

// Function to count the number of possible checkouts given a range of starting and ending indices
int countCheckOuts(const std::vector<int>& landings, int start, int end, int upperBound) {
    int nCheckOuts = 0;

    // Outer loop iterates over the possible starting positions
    for (int i = start; i <= end; ++i) {
        int sum = landings[i];

        // Check if the sum is below the upper bound and increment the count
        if (sum < upperBound) {
            ++nCheckOuts;
        }

        // Middle loop represents the second dart
        for (int j = 0; j < landings.size(); ++j) {
            int secondDart = landings[j];
            sum += secondDart;

            // Check if the sum is below the upper bound and increment the count
            if (sum < upperBound) {
                ++nCheckOuts;
            }

            // Inner loop represents the third dart
            for (int k = j; k < landings.size(); ++k) {
                int thirdDart = landings[k];
                sum += thirdDart;

                // Check if the sum is below the upper bound and increment the count
                if (sum < upperBound) {
                    ++nCheckOuts;
                }

                sum -= thirdDart; // Reset the sum for the next iteration
            }

            sum -= secondDart; // Reset the sum for the next iteration
        }
    }

    return nCheckOuts;
}

int main(int argc, char* argv[]) {
    // Check if the required command-line argument is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-109-Darts <value_of_n>" << std::endl;
        return 0;
    }

    // Parse the command-line argument
    char* endPtr;
    int upperBound = std::strtol(argv[1], &endPtr, 10);

    // Check for conversion errors
    if (*endPtr != '\0') {
        std::cout << "Error: Invalid input. Please enter a valid number" << std::endl;
        return 0;
    }

    // Vector to store possible dart landing values
    std::vector<int> landings;

    // Push in doubles
    for (int i = 1; i <= 20; ++i) {
        landings.push_back(2 * i);
    }
    landings.push_back(2 * 25);

    // Push in singles
    for (int i = 1; i <= 20; ++i) {
        landings.push_back(i);
    }
    landings.push_back(25);

    // Push in trebles
    for (int i = 1; i <= 20; ++i) {
        landings.push_back(3 * i);
    }

    // Count the number of possible checkouts and output the result
    int nCheckOuts = countCheckOuts(landings, 0, 20, upperBound);
    std::cout << nCheckOuts << std::endl;

    return 0;
}
