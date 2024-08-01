#ifndef NEUROCLUE_JSONHANDLER_H
#define NEUROCLUE_JSONHANDLER_H


#include "FileHandler.h"
#include <string>
#include <nlohmann/json.hpp>

class JsonHandler : public FileHandler {
    nlohmann::json jsonData;

public:
    void readData(const std::string& filePath) override;
    void processData() override;
    void writeData(const std::string& filePath) override;
};


#endif //NEUROCLUE_JSONHANDLER_H
