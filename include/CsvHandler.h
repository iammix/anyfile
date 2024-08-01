#ifndef NEUROCLUE_CSVHANDLER_H
#define NEUROCLUE_CSVHANDLER_H

#include "FileHandler.h"
#include <vector>
#include <string>

class CsvHandler : public FileHandler {
    std::vector<std::vector<std::string>> csvData;

public:
    void readData(const std::string& filePath) override;
    void processData() override;
    void writeData(const std::string& filePath) override;
};



#endif //NEUROCLUE_CSVHANDLER_H
