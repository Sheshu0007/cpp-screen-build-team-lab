#pragma once

#include "common/screen.h"
#include "common/session_service.h"

namespace lab {

class ProfileScreen final : public Screen {
public:
    explicit ProfileScreen(const SessionService& session);
    std::string name() const override;
    std::string render() const override;

private:
    const SessionService& session_;
};

} // namespace lab
