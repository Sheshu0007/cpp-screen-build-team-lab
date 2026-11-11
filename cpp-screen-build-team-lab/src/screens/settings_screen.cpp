#include "screens/settings_screen.h"

namespace lab {

std::string SettingsScreen::name() const {
    return "settings";
}

std::string SettingsScreen::render() const {
    return "Settings: [theme=light, notifications=on]";
}

} // namespace lab
