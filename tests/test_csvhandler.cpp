#include "CsvHandler.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    CsvHandler handler;
    handler.readData("test_data.csv");  // Assume test_data.csv exists
    handler.processData();
    handler.writeData("output.csv");

    std::ifstream file("output.csv");
    std::string line;
    bool test_passed = true;

    // Skip header
    std::getline(file, line);

    // Check the first data row (for example)
    std::getline(file, line);
    if (line != "0.00,1.0,2.0,3.0,3.741657") { // Replace with expected output
        std::cerr << "Test failed: incorrect total acceleration." << std::endl;
        test_passed = false;
    }
    file.close();
    return test_passed ? 0 : 1;  // Return 0 if passed, non-zero if failed
}
