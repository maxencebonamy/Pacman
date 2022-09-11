#include "pinky.hpp"


Pinky::Pinky(std::shared_ptr<Map> map, const Vector2& position) :
    Ghost(std::move(map), position, "pinky")
{}
