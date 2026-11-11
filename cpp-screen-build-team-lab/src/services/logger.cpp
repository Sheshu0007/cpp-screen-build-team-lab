#include "common/logger.h"

#include <iostream>

namespace lab {

void Logger::info(const std::string& message) {
    std::cout << "[INFO] " << message << '\n';
}

void Logger::warning(const std::string& message) {
    std::cout << "[WARNING] " << message << '\n';
}

} // namespace lab
