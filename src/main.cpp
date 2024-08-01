#include "FileDump.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a file path as an argument.\n";
        return 1;
    }

    std::string filePath = argv[1];
    auto fileHandler = FileDump::createFileHandler(filePath);

    if (!fileHandler) {
        std::cerr << "Unsupported file type.\n";
        return 1;
    }

    fileHandler->readData(filePath);
    fileHandler->processData();
    fileHandler->writeData(filePath);

    std::cout << "Processing complete.\n";

    return 0;
}
