#include <exception>
#include <iostream>

void test_session_service();
void test_screen_registry();

int main() {
    try {
        test_session_service();
        test_screen_registry();
        std::cout << "All training tests passed.\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "TEST FAILURE: " << error.what() << '\n';
        return 1;
    }
}
