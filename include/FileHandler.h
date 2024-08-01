#ifndef NEUROCLUE_FILEHANDLER_H
#define NEUROCLUE_FILEHANDLER_H

#include <string>

class FileHandler {
public:
    virtual ~FileHandler() = default;
    virtual void readData(const std::string& filePath) = 0;
    virtual void processData() = 0;
    virtual void writeData(const std::string& filePath) = 0;
};

#endif
