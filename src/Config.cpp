#include "Config.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <algorithm>

bool Config::s_loaded = false;
std::map<std::string, std::string> Config::s_serverIPs;
std::string Config::s_logPath;
int Config::s_maxRetryCount = 3;

namespace {
    std::string trim(const std::string& str)
    {
        size_t first = str.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t\r\n");
        return str.substr(first, last - first + 1);
    }
}

bool Config::load(const std::string& configPath)
{
    std::ifstream file(configPath);
    if (!file.is_open()) {
        AppLog::error("Config", "Failed to open config file.");
        return false;
    }

    std::string line;
    std::string currentSection;

    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }

        if (line[0] == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.size() - 2);
            continue;
        }

        size_t equalPos = line.find('=');
        if (equalPos == std::string::npos) {
            continue;
        }

        std::string key = trim(line.substr(0, equalPos));
        std::string value = trim(line.substr(equalPos + 1));

        if (currentSection == "Server") {
            s_serverIPs[key] = value;
        }
        else if (currentSection == "Paths") {
            if (key == "LogDirectory") {
                s_logPath = value;
            }
        }
        else if (currentSection == "Limits") {
            if (key == "MaxRetryCount") {
                s_maxRetryCount = std::stoi(value);
            }
        }
    }

    s_loaded = true;
    AppLog::info("Config", "Configuration loaded successfully.");
    return true;
}

std::string Config::getServerIP(const std::string& key)
{
    if (!s_loaded) {
        AppLog::warning("Config", "Config not loaded. Call Config::load() first.");
        return "";
    }

    auto it = s_serverIPs.find(key);
    if (it != s_serverIPs.end()) {
        return it->second;
    }
    return "";
}

std::string Config::getLogPath()
{
    if (!s_loaded) {
        AppLog::warning("Config", "Config not loaded. Call Config::load() first.");
        return "";
    }
    return s_logPath;
}

int Config::getMaxRetryCount()
{
    return s_maxRetryCount;
}

bool Config::isLoaded()
{
    return s_loaded;
}
