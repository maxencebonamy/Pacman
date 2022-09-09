#include "grid.hpp"

#include <utility>


// Constructors

Grid::Grid(std::shared_ptr<Map> map) :
    _map(std::move(map))
{
    const float windowRatio { config::WINDOW_SIZE.getX() / config::WINDOW_SIZE.getY() },
                mapRatio { _map->getSize().getX() / _map->getSize().getY() };

    if (windowRatio >= mapRatio) {
        _cellSize = config::WINDOW_SIZE.getY() / _map->getSize().getY();

        const Vector2 mapPos {
            (config::WINDOW_SIZE.getX() - _map->getSize().getX() * _cellSize) / 2,
            0
        };
        _map->setPosition(mapPos);
    }

    else {
        _cellSize = config::WINDOW_SIZE.getX() / _map->getSize().getX();

        const Vector2 mapPos {
            0,
            (config::WINDOW_SIZE.getY() - _map->getSize().getY() * _cellSize) / 2
        };
        _map->setPosition(mapPos);
    }


    for (int y { 0 }; y < static_cast<int>(_map->getSize().getY()); ++y) {
        _imageMap.emplace_back();
        for (int x { 0 }; x < static_cast<int>(_map->getSize().getX()); ++x) {
            Vector2 pos { static_cast<float>(x), static_cast<float>(y) };
            _imageMap[y].emplace_back(_map->getTileAt(pos), _cellSize);
            _imageMap[y][x].init(_map->getPosition() + _cellSize * pos);
        }
    }
}


// Public Methods

void Grid::display(sf::RenderWindow& window) {
    for (int y { 0 }; y < static_cast<int>(_map->getSize().getY()); ++y) {
        for (int x { 0 }; x < static_cast<int>(_map->getSize().getX()); ++x) {
            Vector2 pos { static_cast<float>(x), static_cast<float>(y) };
            _imageMap[y][x].setPosition(_map->getPosition() + _cellSize * pos);
            _imageMap[y][x].display(window);
        }
    }
}