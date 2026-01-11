#pragma once
#include <string>
#include <map>

class Config {
public:
    static bool load(const std::string& configPath);
    static std::string getServerIP(const std::string& key);
    static std::string getLogPath();
    static int getMaxRetryCount();
    static bool isLoaded();

private:
    Config() = default;
    static bool s_loaded;
    static std::map<std::string, std::string> s_serverIPs;
    static std::string s_logPath;
    static int s_maxRetryCount;
};
