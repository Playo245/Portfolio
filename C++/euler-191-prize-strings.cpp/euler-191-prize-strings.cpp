#include <iostream> // Input and output cases, used for displaying messages to the command line
#include <cstdlib>  // String functions, used for atoi function to convert string to int
#include <vector>   // Dynamic arrays, used to represent a 3D array for prizelist

// Constants representing the number of days, absences, and being late
const int Absent = 2;
const int Late = 1;

// Class encapsulating the functionality for counting prize trinary strings
class PrizeStrings {
public:
    // Constructor to initialize the class with the number of days
    PrizeStrings(int days) : Days(days) {
        // Resize the 3D vector to store results for each combination of days, absence, and lateness
        PrizeList.resize(Days + 1, std::vector<std::vector<int>>(Absent + 1, std::vector<int>(Late + 1, 0)));
    }

    // Method to find the total number of prize trinary strings
    int findTotal() {
        // Base case: There is one way to be present on day 0 with 0 instances of absence, being in, or being late
        PrizeList[0][0][0] = 1;

        // Dynamic programming loop to fill in the array based on recurrence relations
        for (int i = 1; i <= Days; i++) {
            // Loop over instances of absence
            for (int x = 0; x <= Absent; x++) {
                // Loop over instances of lateness
                for (int y = 0; y <= Late; y++) {
                    int sum = 0;

                    // If no instances of absence on the current day
                    if (x == 0) {
                        sum = 0;

                        // Calculate the sum for being on time
                        for (int z = 0; z <= Absent; z++) {
                            sum += PrizeList[i - 1][z][y]; // On time
                        }

                        // If there are instances of being late on the previous day, calculate the sum for being late
                        if (y > 0) {
                            for (int z = 0; z <= Absent; z++) {
                                sum += PrizeList[i - 1][z][y - 1]; // Late
                            }
                        }
                    } else {
                        // If there are instances of absence, consider the sum for being absent
                        sum = PrizeList[i - 1][x - 1][y]; // Absent
                    }

                    // Store the calculated sum in the array
                    PrizeList[i][x][y] = sum;
                }
            }
        }

        // Calculate the total by summing up all the possibilities for the last day
        int total = 0;
        for (int x = 0; x <= Absent; x++) {
            for (int y = 0; y <= Late; y++) {
                total += PrizeList[Days][x][y];
            }
        }

        // Return the total number of possibilities
        return total;
    }

private:
    int Days; // Number of days
    std::vector<std::vector<std::vector<int>>> PrizeList; // 3D vector to store results
};

int main(int argc, char* argv[]) {
    // Check if there are two values inputted
    if (argc != 2) {
        std::cout << "Usage: ./euler-191-prize-strings <day>" << std::endl;
        return 0;
    }

    int days = std::atoi(argv[1]);

    // Error check for invalid input
    if (days <= 0) {
        std::cout << "Invalid input: Please enter a valid day." << std::endl;
        return 0;
    }

    // Create an instance of PrizeStrings with the specified number of days
    PrizeStrings total(days);

    // Find and display the total number of prize trinary strings
    int finalResult = total.findTotal();
    std::cout << finalResult << std::endl;

    return 0;
}
