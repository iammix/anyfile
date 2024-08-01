#include "JsonHandler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <cmath>

using json = nlohmann::json;

int main() {
    JsonHandler handler;
    handler.readData("test_data.json");  // Ensure test_data.json exists
    handler.processData();
    handler.writeData("output.json");

    std::ifstream file("output.json");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open output.json" << std::endl;
        return 1;
    }

    json outputJson;
    file >> outputJson;
    file.close();

    bool test_passed = true;

    // Assuming 'records' is the main array in the JSON and contains objects
    for (const auto& record : outputJson["records"]) {
        double ax = record["ax"].get<double>();
        double ay = record["ay"].get<double>();
        double az = record["az"].get<double>();
        double expected_total_acceleration = sqrt(ax*ax + ay*ay + az*az);

        if (fabs(record["total_acceleration"].get<double>() - expected_total_acceleration) > 0.0001) {
            std::cerr << "Test failed: incorrect total acceleration for record: "
                      << record << std::endl;
            test_passed = false;
        }
    }

    return test_passed ? 0 : 1;  // Return 0 if the test passed, non-zero otherwise
}
