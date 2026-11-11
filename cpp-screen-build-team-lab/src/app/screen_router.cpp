#include "app/screen_router.h"

#include <algorithm>
#include <stdexcept>

namespace lab {

void ScreenRouter::register_screen(std::shared_ptr<Screen> screen) {
    if (!screen) {
        throw std::invalid_argument("screen must not be null");
    }
    if (contains(screen->name())) {
        throw std::invalid_argument("screen already registered: " + screen->name());
    }
    screens_.push_back(std::move(screen));
}

bool ScreenRouter::contains(const std::string& screen_name) const {
    return std::any_of(screens_.begin(), screens_.end(),
        [&screen_name](const auto& screen) {
            return screen->name() == screen_name;
        });
}

std::vector<std::string> ScreenRouter::screen_names() const {
    std::vector<std::string> names;
    names.reserve(screens_.size());
    for (const auto& screen : screens_) {
        names.push_back(screen->name());
    }
    return names;
}

} // namespace lab
