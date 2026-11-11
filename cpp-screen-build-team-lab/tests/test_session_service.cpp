#include "common/session_service.h"

#include <stdexcept>
#include <string>

void test_session_service() {
    lab::SessionService session;
    if (session.is_signed_in()) {
        throw std::runtime_error("new session should be signed out");
    }

    session.sign_in("alex");
    if (!session.is_signed_in() || session.username() != "alex") {
        throw std::runtime_error("sign-in state was not stored");
    }

    session.sign_out();
    if (session.is_signed_in() || !session.username().empty()) {
        throw std::runtime_error("sign-out did not clear session");
    }
}
