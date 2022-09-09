#pragma once

#include <memory>

#include "config.hpp"
#include "map/map.hpp"
#include "image.hpp"


class Grid {

public:
    // Constructors
    explicit Grid(std::shared_ptr<Map> map);

    // Big Five
    Grid(const Grid& grid) = delete;
    Grid(Grid&& grid) noexcept = delete;
    Grid& operator=(const Grid& grid) = delete;
    Grid& operator=(Grid&& grid) noexcept = delete;
    ~Grid() = default;

    // Public Methods
    void display(sf::RenderWindow& window);

private:
    std::shared_ptr<Map> _map;
    float _cellSize;

    std::vector<std::vector<Image>> _imageMap;
};
