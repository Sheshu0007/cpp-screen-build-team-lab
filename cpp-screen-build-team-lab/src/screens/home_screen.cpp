#include "screens/home_screen.h"

namespace lab {

std::string HomeScreen::name() const {
    return "home";
}

std::string HomeScreen::render() const {
    return "Welcome to the Screen Lab";
}

} // namespace lab
