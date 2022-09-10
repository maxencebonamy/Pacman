#include "player.hpp"


// Constructors

Player::Player(std::shared_ptr<Map> map, const Vector2& position) :
    Entity(std::move(map), position),
    _image("pacman/walk/walk_" + directionToName(_direction), _map->getCellSize() * 2)
{}


// Setters

void Player::setDirection(Direction direction) {
    if (!_isDead) {
        Entity::setDirection(direction);
        _updateImage();
    }
}


// Public Methods

void Player::update() {
    if (!_isDead) {
        setPosition(_position + _speed * directionToVector(_direction));
    }
    if (!_image.hasFinished()) {
        _image.updateFrame();
    }
}

void Player::display(sf::RenderWindow& window) {
    _image.setPosition(_map->getPosition() + _map->getCellSize() * (_position - 0.5*Vector2::one()));
    _image.display(window);
}

void Player::kill() {
    _isDead = true;
    _image = AnimatedImage("pacman/death/death", _map->getCellSize() * 2, 12);
    _image.disableLoop();
}


// Private Methods

void Player::_updateImage() {
    _image = AnimatedImage("pacman/walk/walk_" + directionToName(_direction), _map->getCellSize() * 2);
}