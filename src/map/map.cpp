#include "map.hpp"


// Constructors

Map::Map(std::string name) :
    _name(std::move(name)),
    _cellSize(1)
{
    _loadMapFile();
    _loadWindowProperties();
    _loadImages();
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

const std::string& Map::getTileAt(const Vector2& position) const {
    return _stringMap[static_cast<int>(position.getY())][static_cast<int>(position.getX())];
}



// Public Methods

void Map::display(sf::RenderWindow& window) {
    for (int y { 0 }; y < static_cast<int>(_size.getY()); ++y) {
        for (int x { 0 }; x < static_cast<int>(_size.getX()); ++x) {
            Vector2 pos { static_cast<float>(x), static_cast<float>(y) };
            const std::string& element { _stringMap[y][x] };
            Image& image { _images.at(element) };

            image.setPosition(_position + _cellSize * pos);
            image.display(window);
        }
    }
}


// Private Methods

void Map::_loadMapFile() {
    std::ifstream file { "res/map/" + _name + ".txt" };
    std::string line;

    while (std::getline(file, line)) {
        line += ';';
        _stringMap.emplace_back();
        std::string element;

        for (auto& c : line) {
            if (c == ';') {
                _stringMap[_stringMap.size() - 1].emplace_back(element);
                element.clear();
            }
            else {
                element += c;
            }
        }
    }

    _size = Vector2(
        static_cast<float>(_stringMap.empty() ? 0 : _stringMap[0].size()),
        static_cast<float>(_stringMap.size())
    );
}

void Map::_loadWindowProperties() {
    const float windowRatio { config::WINDOW_SIZE.getX() / config::WINDOW_SIZE.getY() },
                mapRatio { getSize().getX() / getSize().getY() };

    if (windowRatio >= mapRatio) {
        _cellSize = config::WINDOW_SIZE.getY() / getSize().getY();

        _position = {
            (config::WINDOW_SIZE.getX() - getSize().getX() * _cellSize) / 2,
            0
        };
    }

    else {
        _cellSize = config::WINDOW_SIZE.getX() / getSize().getX();

        _position = {
            0,
            (config::WINDOW_SIZE.getY() - getSize().getY() * _cellSize) / 2
        };
    }
}

void Map::_loadImages() {
    std::vector<std::string> _names;

    for (const auto& line : _stringMap) {
        for (const auto& element : line) {
            if (std::find(_names.begin(), _names.end(), element) == _names.end()) {
                _images.insert({ element, Image("map/" + element, _cellSize) });
                _names.emplace_back(element);
            }
        }
    }
}
