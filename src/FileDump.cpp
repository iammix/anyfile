#include "FileDump.h"
#include "JsonHandler.h"
#include "CsvHandler.h"
#include <string>

bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() >= suffix.length()) {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    } else {
        return false;
    }
}


std::unique_ptr<FileHandler> FileDump::createFileHandler(const std::string& filePath) {
    if (endsWith(filePath, ".json")) {
        return std::make_unique<JsonHandler>();
    } else if (endsWith(filePath, ".csv")) {
        return std::make_unique<CsvHandler>();
    } else {
        return nullptr;
    }
}