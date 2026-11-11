cmake_minimum_required(VERSION 3.20)

project(CppScreenBuildTeamLab
    VERSION 1.0.0
    DESCRIPTION "Team training project for C++ screen modules and CMake builds"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(SCREEN_LAB_BUILD_TESTS "Build the training tests" ON)

add_library(screen_core
    src/services/logger.cpp
    src/services/session_service.cpp
)
target_include_directories(screen_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(screen_core PUBLIC cxx_std_17)

add_library(screen_modules
    src/screens/home_screen.cpp
    src/screens/profile_screen.cpp
    src/screens/settings_screen.cpp
)
target_include_directories(screen_modules PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(screen_modules PUBLIC screen_core)

add_executable(screen_demo
    src/app/main.cpp
    src/app/screen_router.cpp
)
target_link_libraries(screen_demo PRIVATE screen_modules)

if(MSVC)
    target_compile_options(screen_core PRIVATE /W4)
    target_compile_options(screen_modules PRIVATE /W4)
    target_compile_options(screen_demo PRIVATE /W4)
else()
    target_compile_options(screen_core PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(screen_modules PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(screen_demo PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(SCREEN_LAB_BUILD_TESTS)
    enable_testing()
    add_executable(screen_tests
        tests/test_main.cpp
        tests/test_session_service.cpp
        tests/test_screen_registry.cpp
    )
    target_link_libraries(screen_tests PRIVATE screen_modules)
    add_test(NAME screen_tests COMMAND screen_tests)
endif()
