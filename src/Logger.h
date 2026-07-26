//
// Created by david on 2026-07-26.
//

#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H


#include <fstream>
#include <string>

enum class LogLevel
{
    Info,
    Warning,
    Error,
    Fatal,
    Suspicious
};

static constexpr const char* levelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Info: return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error: return "ERROR";
        case LogLevel::Fatal: return "FATAL";
        case LogLevel::Suspicious: return "SUSPICIOUS";
    }

    return "UNKNOWN";
}

class Logger {
public:
    Logger();
    ~Logger();

    static void disableInfoPrints() { displayInfo = false; };

    static void log(const std::string& msg, LogLevel level);
private:
    static void initializeConsole();

    static std::string getCurrentTime() ;
    static void setColor(LogLevel level);
    static void resetColor();

    inline static bool displayInfo = true;
    static std::ofstream logFile;
};

#define LOG_INFO(msg)    Logger::log(msg, LogLevel::Info)
#define LOG_WARNING(msg) Logger::log(msg, LogLevel::Warning)
#define LOG_ERROR(msg)   Logger::log(msg, LogLevel::Error)
#define LOG_FATAL(msg)   Logger::log(msg, LogLevel::Fatal)
#define LOG_SUSPICIOUS(msg)   Logger::log(msg, LogLevel::Suspicious)

#endif //GAME_LOGGER_H