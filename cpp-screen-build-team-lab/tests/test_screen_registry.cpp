#include "app/screen_router.h"
#include "screens/home_screen.h"

#include <memory>
#include <stdexcept>

void test_screen_registry() {
    lab::ScreenRouter router;
    router.register_screen(std::make_shared<lab::HomeScreen>());

    if (!router.contains("home")) {
        throw std::runtime_error("home screen was not registered");
    }
    if (router.contains("missing")) {
        throw std::runtime_error("unknown screen should not be registered");
    }
}
