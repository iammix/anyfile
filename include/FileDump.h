#ifndef NEUROCLUE_FILEDUMP_H
#define NEUROCLUE_FILEDUMP_H

#include "FileHandler.h"
#include <memory>
#include <string>

class FileDump {
public:
    static std::unique_ptr<FileHandler> createFileHandler(const std::string& filePath);
};

#endif

