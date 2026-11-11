#include "app/screen_router.h"
#include "common/logger.h"
#include "common/session_service.h"
#include "screens/home_screen.h"
#include "screens/profile_screen.h"
#include "screens/settings_screen.h"

#include <iostream>
#include <memory>

int main() {
    lab::SessionService session;
    session.sign_in("team-member");

    lab::ScreenRouter router;
    router.register_screen(std::make_shared<lab::HomeScreen>());
    router.register_screen(std::make_shared<lab::ProfileScreen>(session));
    router.register_screen(std::make_shared<lab::SettingsScreen>());

    lab::Logger::info("Registered screens:");
    for (const auto& name : router.screen_names()) {
        std::cout << " - " << name << '\n';
    }

    lab::HomeScreen home;
    lab::ProfileScreen profile(session);
    lab::SettingsScreen settings;

    std::cout << '\n' << home.render() << '\n';
    std::cout << profile.render() << '\n';
    std::cout << settings.render() << '\n';
    return 0;
}
