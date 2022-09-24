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

std::array<Direction, 4> getAllRandomDirections() {
    std::array<Direction, 4> output {};

    std::array<Direction, 4> directions = {
        Direction::LEFT,
        Direction::RIGHT,
        Direction::UP,
        Direction::DOWN
    };

    for (int i { 0 }; i < 4; ++i) {
        Direction dir;

        do {
            dir = directions[rand() % 4];
        } while (std::find(output.begin(), output.end(), dir) != output.end());

        output[i] = dir;
    }

    return output;
}