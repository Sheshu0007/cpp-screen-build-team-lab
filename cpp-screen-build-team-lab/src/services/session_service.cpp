#include "common/session_service.h"

#include <stdexcept>

namespace lab {

void SessionService::sign_in(const std::string& username) {
    if (username.empty()) {
        throw std::invalid_argument("username must not be empty");
    }
    username_ = username;
    signed_in_ = true;
}

void SessionService::sign_out() {
    signed_in_ = false;
    username_.clear();
}

bool SessionService::is_signed_in() const {
    return signed_in_;
}

std::string SessionService::username() const {
    return username_;
}

} // namespace lab
