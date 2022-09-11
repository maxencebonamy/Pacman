#include "clyde.hpp"


Clyde::Clyde(std::shared_ptr<Map> map, const Vector2& position) :
    Ghost(std::move(map), position, "clyde")
{}
