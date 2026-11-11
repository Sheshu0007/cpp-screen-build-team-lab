#pragma once

#include "common/screen.h"

#include <memory>
#include <string>
#include <vector>

namespace lab {

class ScreenRouter {
public:
    void register_screen(std::shared_ptr<Screen> screen);
    bool contains(const std::string& screen_name) const;
    std::vector<std::string> screen_names() const;

private:
    std::vector<std::shared_ptr<Screen>> screens_;
};

} // namespace lab
