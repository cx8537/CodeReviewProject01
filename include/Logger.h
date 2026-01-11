#pragma once

namespace AppLog {
    enum class Level {
        Debug,
        Info,
        Warning,
        Error
    };

    void setMinLevel(Level level);
    void error(const char* module, const char* message);
    void warning(const char* module, const char* message);
    void info(const char* module, const char* message);
    void debug(const char* module, const char* message);
}
