#pragma once

#include <string>

namespace lab {

class Logger {
public:
    static void info(const std::string& message);
    static void warning(const std::string& message);
};

} // namespace lab
