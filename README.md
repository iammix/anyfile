# Anyfile Project

## Overview

Anyfile Project is a C++ application designed to handle and process data from CSV and JSON files (or custom formatted - implementation needed), in my case, focusing on accelerometer data. The application reads data, computes the total acceleration for each record, and writes the processed data back to an output file.

## Features

- **Data Handling**: Supports both CSV and JSON formats for input and output.
- **Computation**: Calculates total acceleration from accelerometer readings.
- **Cross-Platform Compatibility**: Compatible with both Linux and Windows environments.
- **Unit Tests**: Includes unit tests to validate functionality.

## Prerequisites

- **C++ Compiler**: GCC (Linux), MinGW (Windows), or Visual Studio (Windows).
- **CMake**: Version 3.20 or higher.
- **Python**: Version 3.7 or higher. (For generating the data.csv and data.json files)

## Project Structure
```
anyfile/
├── CMakeLists.txt              # CMake Main configuration
├── include/                    # Header files
│   ├── FileDump.h              # Header for file dump
│   ├── CsvHandler.h            # CSV handler header
│   ├── JsonHandler.h           # JSON handler header
│   └── FileHandler.h           # File handler header
├── src/                        # Source files
│   ├── main.cpp                # Entry point for the application
│   ├── JsonHandler.            # JSON handler implementation
│   ├── CsvHandler.cpp          # CSV handler implementation
│   ├── FileDump.cpp            # Dump for file handlers
├── tests/                      # Test files
│   ├── test_csvhandler.cpp     # Unit tests for CSV handler
│   ├── test_jsonhandler.cpp    # Unit tests for JSON handler
│   └── CMakeLists.txt          # CMake configuration for tests
├── external/                   # External dependencies (e.g., nlohmann/json)
│   └── json/
├── test_data/                  # Directory for test data files
│   ├── test_data.csv
│   └── test_data.json
├── data_generation.py          # .json and .csv file generator
├── data.csv                    # appears after executing data_generation.py
├── data.json                   # appears after executing data_generation.py
└── README.md                   # this file
```
## Setup Instructions

### Clone the Repository

```bash
git clone https://github.com/iammix/anyfile.git
cd anyfile
```
### Windows(MinGW)
```
# Navigate to the project directory
cd C:\Path\To\Your\Project

# Generate data.csv and data.json files
python data_generation.py

# Create and navigate to the build directory
mkdir build
cd build

# Configure the project with CMake using MinGW Makefiles
cmake -G "MinGW Makefiles" ..

# Build the project using mingw32-make
mingw32-make

# Run the tests using CTest
ctest

# Run the main application
.build/anyfile.exe data.json
or
.build/anyfile.exe data.csv
```
### Unix-based System
```
# Navigate to the project directory
cd /Path/To/Your/Project

# Generate data.csv and data.json files
python data_generation.py


# Create and navigate to the build directory
mkdir build
cd build

# Configure the project with CMake using MinGW Makefiles
cmake ..

# Build the project using mingw32-make
make

# Run the tests using CTest
ctest

# Run the main application
.build/anyfile data.json
or
.build/anyfile data.csv
```
## Extending the Application with Custom File Types
To extend the Anyfile Project to support custom file types, see the following steps:

### 1. Implement a New Handler
Create a new handler class in the *src/* directory. This class should inherit from FileHandler and implement the readData, processData, and writeData methods.
#### Example: CustomHandler
#### CustomHandler.h
```cpp
#ifndef CUSTOMHANDLER_H
#define CUSTOMHANDLER_H

#include "FileHandler.h"
#include <string>
#include <vector>

class CustomHandler : public FileHandler {
public:
    void readData(const std::string& filePath) override;
    void processData() override;
    void writeData(const std::string& filePath) override;

private:
    std::vector<std::pair<std::string, double>> customData;
};

#endif

```
#### CustomHandler.cpp
```cpp
#include "CustomHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void CustomHandler::readData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key;
        double value;
        if (ss >> key >> value) {
            customData.push_back({key, value});
        }
    }

    file.close();
}

void CustomHandler::processData() {
    // Code for processing data

}

void CustomHandler::writeData(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
        return;
    }

    for (const auto& entry : customData) {
        file << entry.first << " " << entry.second << "\n";
    }

    file.close();
}

```
### 2. Update FileDump
Modify the FileDump class to recognize and instantiate the new handler based on the custom file extension.

```cpp
#include "FileDump.h"
#include "CsvHandler.h"
#include "JsonHandler.h"
#include "CustomHandler.h"

std::unique_ptr<FileHandler> FileDump::createHandler(const std::string& filePath) {
    if (filePath.ends_with(".csv")) {
        return std::make_unique<CsvHandler>();
    } else if (filePath.ends_with(".json")) {
        return std::make_unique<JsonHandler>();
    // Add your custom handler as below
    } else if (filePath.ends_with(".custom")) {
        return std::make_unique<CustomHandler>();
    } else {
        std::cerr << "Unsupported file type: " << filePath << std::endl;
        return nullptr;
    }
}


```

By following these steps, you can easily extend the Anyfile Project to support new file formats with minimal changes to the existing codebase, ensuring flexibility and adaptability for various data formats.


## Acknowledgements
- nlohmann/json - JSON for Modern C++
- CMake - Build system generator
