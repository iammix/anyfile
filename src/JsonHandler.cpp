#include "JsonHandler.h"
#include <fstream>
#include <cmath>
#include <iostream>

using json = nlohmann::json;

void JsonHandler::readData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        file >> jsonData;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }
}

void JsonHandler::processData() {
    if (jsonData.contains("records") && jsonData["records"].is_array()) {
        for (auto& record : jsonData["records"]) {
            if (record.contains("ax") && record.contains("ay") && record.contains("az")) {
                try {
                    double ax = record["ax"].get<double>();
                    double ay = record["ay"].get<double>();
                    double az = record["az"].get<double>();
                    double total_acceleration = std::sqrt(ax * ax + ay * ay + az * az);
                    record["total_acceleration"] = total_acceleration;
                } catch (const std::exception& e) {
                    std::cerr << "Error processing record: " << e.what() << std::endl;
                }
            }
        }
    }
}

void JsonHandler::writeData(const std::string& filePath) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << jsonData.dump(4);
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
    }
}