#pragma once

#include "ghost.hpp"


class Blinky final : public Ghost {

public:
    // Constructors
    Blinky(std::shared_ptr<Map> map, const Vector2& position);

    // Public Methods
    void update() override;

private:

};
