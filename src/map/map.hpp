#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "config.hpp"
#include "utils/vector2.hpp"
#include "images/image.hpp"


class Map final {

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
    float getCellSize() const;
    const std::string& getTileAt(const Vector2& position) const;

    // Public Methods
    void display(sf::RenderWindow& window);

private:
    // Private Methods
    void _loadMapFile();
    void _loadWindowProperties();
    void _loadImages();

    // Attributes
    std::string _name;
    Vector2 _position;
    Vector2 _size;
    float _cellSize;

    std::vector<std::vector<std::string>> _stringMap;
    std::map<std::string, Image> _images;

};
