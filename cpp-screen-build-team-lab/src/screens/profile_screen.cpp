#include "screens/profile_screen.h"

namespace lab {

ProfileScreen::ProfileScreen(const SessionService& session) : session_(session) {}

std::string ProfileScreen::name() const {
    return "profile";
}

std::string ProfileScreen::render() const {
    if (!session_.is_signed_in()) {
        return "Profile unavailable: sign in first";
    }
    return "Profile for " + session_.username();
}

} // namespace lab
