#include "ghost.hpp"


// Constructors

Ghost::Ghost(std::shared_ptr<Map> map, const Vector2& position, std::string name) :
    Entity(std::move(map), position),
    _name(std::move(name)),
    _image("ghosts/" + _name + "/" + _name + "_" + directionToName(_direction), _map->getCellSize() * 2)
{}


// Public Methods

void Ghost::update() {
    _image.updateFrame();
}

void Ghost::display(sf::RenderWindow& window) {
    _image.setPosition(_map->getPosition() + _map->getCellSize() * (_position - 0.5*Vector2::one()));
    _image.display(window);
}
