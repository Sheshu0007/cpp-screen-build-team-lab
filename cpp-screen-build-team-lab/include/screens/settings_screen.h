#pragma once

#include "common/screen.h"

namespace lab {

class SettingsScreen final : public Screen {
public:
    std::string name() const override;
    std::string render() const override;
};

} // namespace lab
