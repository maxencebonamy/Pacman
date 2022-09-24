#pragma once

#include <string>

#include "utils/vector2.hpp"


enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};


Vector2 directionToVector(Direction direction);
std::string directionToName(Direction direction);
std::array<Direction, 4> getAllRandomDirections();
