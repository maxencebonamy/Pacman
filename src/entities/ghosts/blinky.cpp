#include "blinky.hpp"

Blinky::Blinky(std::shared_ptr<Map> map, const Vector2& position) :
    Ghost(std::move(map), position, "blinky")
{}
