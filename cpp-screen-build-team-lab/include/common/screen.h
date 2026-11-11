#pragma once

#include <string>

namespace lab {

class Screen {
public:
    virtual ~Screen() = default;
    virtual std::string name() const = 0;
    virtual std::string render() const = 0;
};

} // namespace lab
