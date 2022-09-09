#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "vector/vector2.hpp"


class Map {

public:
    // Constructors
    explicit Map(std::string name);

    // Big Five
    Map(const Map& map) = default;
    Map(Map&& map) noexcept = default;
    Map& operator=(const Map& map) = default;
    Map& operator=(Map&& map) noexcept = default;
    ~Map() = default;

    // Getters
    const std::string& getName() const;
    const Vector2& getPosition() const;
    const Vector2& getSize() const;
    std::string getTileAt(const Vector2& position) const;

    // Setters
    void setPosition(const Vector2& position);

    // Public Methods
    void print() const;


private:
    std::string _name;
    Vector2 _position;
    Vector2 _size;

    std::vector<std::string> _charMap;

};
