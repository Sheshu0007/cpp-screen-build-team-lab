#pragma once

#include <string>

namespace lab {

class SessionService {
public:
    void sign_in(const std::string& username);
    void sign_out();
    bool is_signed_in() const;
    std::string username() const;

private:
    bool signed_in_{false};
    std::string username_;
};

} // namespace lab
