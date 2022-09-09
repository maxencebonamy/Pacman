#include "map.hpp"


// Constructors

Map::Map(std::string name) :
    _name(std::move(name))
{
    std::ifstream file { "res/map/" + _name + ".txt" };

    std::string line;
    while (std::getline(file, line)) {
        _charMap.emplace_back(line);
    }

    _size = Vector2(
        static_cast<float>(_charMap[0].size()),
        static_cast<float>(_charMap.size())
    );
}


// Getters

const std::string& Map::getName() const {
    return _name;
}

const Vector2& Map::getPosition() const {
    return _position;
}

const Vector2& Map::getSize() const {
    return _size;
}

std::string Map::getTileAt(const Vector2& position) const {
//    return _charMap[position.getY()][position.getX()];
    char c { _charMap[static_cast<int>(position.getY())][static_cast<int>(position.getX())] };

    if (c == '_') {
        return "void";
    }
    else if (c == 'W') {
        // Corners
        if (position.getX() == 0 && position.getY() == 0) {
            return "walls/top_left_double_wall";
        }
        if (position.getX() == _size.getX() - 1 && position.getY() == 0) {
            return "walls/top_right_double_wall";
        }
        if (position.getX() == 0 && position.getY() == _size.getY() - 1) {
            return "walls/bottom_left_double_wall";
        }
        if (position.getX() == _size.getX() - 1 && position.getY() == _size.getY() - 1) {
            return "walls/bottom_right_double_wall";
        }
        // Borders
        if (position.getX() == 0) {
            return "walls/left_double_wall";
        }
        if (position.getX() == _size.getX() - 1) {
            return "walls/right_double_wall";
        }
        if (position.getY() == 0) {
            return "walls/top_double_wall";
        }
        if (position.getY() == _size.getY() - 1) {
            return "walls/bottom_double_wall";
        }
        // Inside
        if (_charMap[position.getY() + 1][position.getX()] == 'W' &&
                _charMap[position.getY()][position.getX() + 1] == 'W') {
            return "walls/bottom_right_single_wall";
        }
        if (_charMap[position.getY() - 1][position.getX()] == 'W' &&
            _charMap[position.getY()][position.getX() + 1] == 'W') {
            return "walls/top_right_single_wall";
        }
        if (_charMap[position.getY() + 1][position.getX()] == 'W' &&
            _charMap[position.getY()][position.getX() - 1] == 'W') {
            return "walls/bottom_left_single_wall";
        }
        if (_charMap[position.getY() - 1][position.getX()] == 'W' &&
            _charMap[position.getY()][position.getX() - 1] == 'W') {
            return "walls/top_left_single_wall";
        }
        return "walls/bottom_single_wall";
    }
    else if (c == 'o') {
        return "elements/pacgum";
    }
    else if (c == 'O') {
        return "elements/super_pacgum";
    }
    else if (c == 'C') {
        return "center_cell/left_center_cell";
    }
    else if (c == 'D') {
        return "center_cell/door_center_cell";
    }

    return "";
}


// Setters

void Map::setPosition(const Vector2& position) {
    _position = position;
}


// Public Methods

void Map::print() const {
    for (auto& line : _charMap) {
        for (auto& c : line) {
            std::cout << c << ", ";
        }
        std::cout << std::endl;
    }
}
