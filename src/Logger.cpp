#include "Logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <mutex> // 멀티스레드 환경 대비

namespace {
    AppLog::Level g_minLevel = AppLog::Level::Debug;
    std::mutex g_logMutex; // 출력 섞임 방지

    std::string getCurrentTimestamp()
    {
        std::time_t now = std::time(nullptr);
        std::tm localTime = {};
        
        // 플랫폼 호환 스레드 안전 시간 변환
        #if defined(_WIN32) || defined(_WIN64)
            localtime_s(&localTime, &now);
        #else
            localtime_r(&now, &localTime);
        #endif

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

        // 스레드 안전한 출력을 위해 뮤텍스 사용
        std::lock_guard<std::mutex> lock(g_logMutex);
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
