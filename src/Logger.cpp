#include "Logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace {
    AppLog::Level g_minLevel = AppLog::Level::Debug;

    std::string getCurrentTimestamp()
    {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);

        std::ostringstream oss;
        oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    const char* levelToString(AppLog::Level level)
    {
        switch (level) {
            case AppLog::Level::Debug:   return "DEBUG";
            case AppLog::Level::Info:    return "INFO";
            case AppLog::Level::Warning: return "WARN";
            case AppLog::Level::Error:   return "ERROR";
            default: return "UNKNOWN";
        }
    }

    void log(AppLog::Level level, const char* module, const char* message)
    {
        if (level < g_minLevel) {
            return;
        }

        std::cout << "[" << getCurrentTimestamp() << "] "
                  << "[" << levelToString(level) << "] "
                  << "[" << module << "] "
                  << message << std::endl;
    }
}

namespace AppLog {

void setMinLevel(Level level)
{
    g_minLevel = level;
}

void error(const char* module, const char* message)
{
    log(Level::Error, module, message);
}

void warning(const char* module, const char* message)
{
    log(Level::Warning, module, message);
}

void info(const char* module, const char* message)
{
    log(Level::Info, module, message);
}

void debug(const char* module, const char* message)
{
    log(Level::Debug, module, message);
}

} // namespace AppLog

bool getGameLog() { return true; }
void logForUserLogin(const char*) {}
int buildLoginPayload(USER_INFO&) { return 1; }