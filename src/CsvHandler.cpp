#include "CsvHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>

void CsvHandler::readData(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> row;
        while (std::getline(ss, item, ',')) {
            row.push_back(item);
        }
        csvData.push_back(row);
    }
}

void CsvHandler::processData() {
    if (csvData.empty()) return;

    // Add new column header
    csvData[0].push_back("total_acceleration");

    for (size_t i = 1; i < csvData.size(); i++) {
        try {
            double ax = std::stod(csvData[i][1]);
            double ay = std::stod(csvData[i][2]);
            double az = std::stod(csvData[i][3]);
            double total_acceleration = std::sqrt(ax * ax + ay * ay + az * az);
            csvData[i].push_back(std::to_string(total_acceleration));
        } catch (const std::exception& e) {
            std::cerr << "Error processing data on line " << i + 1 << ": " << e.what() << std::endl;
        }
    }
}


void CsvHandler::writeData(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
        return;
    }
    file.imbue(std::locale("C"));
    for (const auto& row : csvData) {
        for (size_t i = 0; i < row.size(); i++) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
}