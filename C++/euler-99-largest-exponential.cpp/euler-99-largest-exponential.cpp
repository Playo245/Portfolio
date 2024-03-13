#include <iostream> // Input/output stream for console input and output
#include <fstream>  // File stream for file input and output
#include <sstream>  // String stream for string manipulation
#include <cmath>    // Math functions, including logarithm

class FindLine {
public:
    // Constructor to initialize the filename
    FindLine(const std::string& filename) : filename(filename) {}

    // Main function to run the FindLine program
    void run() {
        // Check if the file can be opene
        if (!openFile()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        int linenum = 0;            // Variable to keep track of the current line number being processed
        int highestLine = 0;        // Variable to store the line number with the highest total calculated so far
        double highestTotal = 0.0;  // Variable to store the highest total calculated from the logarithmic operation


        std::string line;
        // Read each line from the file
        while (std::getline(file, line)) {
            linenum++;
            int base, exponent;
            // Split the line into base and exponent
            if (!split(line, base, exponent)) {
                std::cout << "Error occurred, couldn't convert to integers: " << line << std::endl;
                return;
            }

            // Calculate the total using logarithm
            double total = calcTotal(base, exponent);

            // Compare the current line total to the highest line total
            if (total > highestTotal) {
                highestLine = linenum;
                highestTotal = total;
            }
        }

        // Print the result based on the line number
        printResult(highestLine);
    }

private:
    std::string filename;
    std::ifstream file;

    // Open the file and return true if successful
    bool openFile() {
        file.open(filename);
        return file.is_open();
    }

    // Calculate the total using logarithm
    double calcTotal(int base, int exponent) {
        return static_cast<double>(exponent) * std::log(static_cast<double>(base));
    }

    // Print the result based on the line number
    void printResult(int line) {
        if (line == 0) {
            std::cout << "No line has been found in the file." << std::endl;
        } else {
            std::cout << line << std::endl;
        }
    }

    // Split the line into base and exponent
    bool split(const std::string& line, int& base, int& exponent) {
        std::istringstream iss(line);
        char comma;

        // Read the base, comma, and exponent from the line
        if (!(iss >> base >> comma >> exponent) || comma != ',' || iss.peek() != EOF) {
            return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        std::cout << "Usage: ./euler-99-largest-exponential <filename>" << std::endl;
        return 0;
    }

    // Create an instance of FindLine and run the program
    FindLine finder(argv[1]);
    finder.run();

    return 0;
}
