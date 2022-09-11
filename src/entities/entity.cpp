#include "entity.hpp"

#include <utility>


// Constructors

Entity::Entity(std::shared_ptr<Map> map, const Vector2& position) :
    _map(std::move(map)),
    _position(position),
    _direction(Direction::UP),
    _nextDirection(_direction)
{}


// Getters

const Vector2& Entity::getPosition() const {
    return _position;
}


// Setters

void Entity::setPosition(const Vector2& position) {
    _position = position;
}

void Entity::setDirection(Direction direction) {
    _direction = direction;
}
