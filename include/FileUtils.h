#pragma once
#include <string>
#include <vector>
#include <cstdint>

class FileUtils {
public:
    static std::vector<std::string> getFilesInDirectory(const std::string& path);
    static std::vector<std::string> getFilesInDirectory(const std::string& path, const std::string& extension);
    static bool readBinaryFile(const std::string& path, std::vector<uint8_t>& outData);
    static bool fileExists(const std::string& path);
    static bool directoryExists(const std::string& path);
    static uint32_t calculateCRC32(const uint8_t* data, size_t size);
};
