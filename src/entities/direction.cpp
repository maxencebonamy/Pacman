#include "direction.hpp"


Vector2 directionToVector(Direction direction) {
    if (direction == Direction::LEFT) return -Vector2::unitX();
    else if (direction == Direction::RIGHT) return Vector2::unitX();
    else if (direction == Direction::UP) return -Vector2::unitY();
    else if (direction == Direction::DOWN) return Vector2::unitY();
    return {};
}

std::string directionToName(Direction direction) {
    if (direction == Direction::LEFT) return "left";
    else if (direction == Direction::RIGHT) return "right";
    else if (direction == Direction::UP) return "up";
    else if (direction == Direction::DOWN) return "down";
    return "";
}