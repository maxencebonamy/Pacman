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
    _nextDirection = direction;
}


// Public Methods

bool Entity::collide(const Entity& entity) const {
    return (_position - entity._position).getNorm() <= 1;
}


// Protected Methods

bool Entity::_isOnCell() const {
    float intX { static_cast<float>(static_cast<int>(_position.getX())) },
          intY { static_cast<float>(static_cast<int>(_position.getY())) };

    return (intX - _speed < _position.getX() && _position.getX() < intX + _speed &&
            intY - _speed < _position.getY() && _position.getY() < intY + _speed);
}

Vector2 Entity::_getNextPosition(Direction direction) const {
    Vector2 nextPosition { _position + directionToVector(direction) };

//    if (nextPosition.getX() < 0) {
//        nextPosition.setX(_map->getSize().getX() - 1);
//    }
//    if (nextPosition.getX() >= _map->getSize().getX()) {
//        nextPosition.setX(0);
//    }
//    if (nextPosition.getY() < 0) {
//        nextPosition.setY(_map->getSize().getY() - 1);
//    }
//    if (nextPosition.getY() >= _map->getSize().getY()) {
//        nextPosition.setY(0);
//    }

    return nextPosition;
}

bool Entity::_canMoveTo(Direction direction) const {
    const std::string& nextCell { _map->getTileAt(_getNextPosition(direction)) };

    return nextCell.substr(0, 5) != "walls" && nextCell.substr(0, 11) != "center_cell";
}
