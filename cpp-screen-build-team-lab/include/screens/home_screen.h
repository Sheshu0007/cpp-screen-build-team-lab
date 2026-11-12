#pragma once

#include "common/screen.h"

namespace lab {

class HelpScreen final : public Screen {
public:
    std::string name() const override;
    std::string render() const override;
};

}