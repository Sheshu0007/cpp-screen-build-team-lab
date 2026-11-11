#include "screens/help_screen.h"

namespace lab {

std::string HelpScreen::name() const {
    return "help";
}

std::string HelpScreen::render() const {
    return "Welcome to Help Screen";
}

}