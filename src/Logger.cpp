//
// Created by david on 2026-07-26.
//

#include <filesystem>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Logger.h"

namespace fs = std::filesystem;
std::ofstream Logger::logFile;

Logger::Logger()
{
    initializeConsole();

    if (!fs::exists("logs"))
    {
        fs::create_directory("logs");
    }

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &t);
#else
    localtime_s(&t, &localTime);
#endif

    std::ostringstream filename;
    filename << "logs/log-" << std::put_time(&localTime, "%Y-%m-%d-%H-%M") << ".txt";

    logFile.open(filename.str(), std::ios::out);

    if (!logFile.is_open())
    {
        std::cerr << "Failed to open log file: " << filename.str() << '\n';
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
        logFile.close();
}

void Logger::initializeConsole()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    SetConsoleMode(hOut, mode);
#endif
}

std::string Logger::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &time);
#else
    localtime_r(&time, &localTime);
#endif

    std::ostringstream ss;
    ss << std::put_time(&localTime, "%H:%M:%S");
    return ss.str();
}

void Logger::setColor(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Info:
            std::cout << "\033[34m";
            break;

        case LogLevel::Warning:
            std::cout << "\033[0;33m";
            break;

        case LogLevel::Error:
            std::cout << "\033[0;91m";
            break;

        case LogLevel::Fatal:
            std::cout << "\033[1;31m";
            break;

        case LogLevel::Suspicious:
            std::cout << "\033[0;35m";
            break;
    }
}

void Logger::resetColor()
{
    std::cout << "\033[0m";
}

void Logger::log(const std::string& msg, LogLevel level)
{
    const std::string log = "[" + getCurrentTime() + "][" + levelToString(level) + "] " + msg;

    if (!(level == LogLevel::Info && !displayInfo))
    {
        setColor(level);
        std::cout << log << '\n';
        resetColor();
    }

    if (logFile.is_open())
        logFile << log << '\n';

    if (level == LogLevel::Fatal)
    {
        std::abort();
    }
}

