#include "inky.hpp"


Inky::Inky(std::shared_ptr<Map> map, const Vector2& position) :
    Ghost(std::move(map), position, "inky")
{}
