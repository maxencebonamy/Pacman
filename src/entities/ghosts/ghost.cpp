#include "ghost.hpp"


// Constructors

Ghost::Ghost(std::shared_ptr<Map> map, const Vector2& position, std::string name) :
    Entity(std::move(map), position),
    _name(std::move(name)),
    _image("ghosts/" + _name + "/" + _name + "_" + directionToName(_direction), _map->getCellSize() * 2)
{}


// Getters

const std::string& Ghost::getName() const {
    return _name;
}

bool Ghost::isScary() const {
    return _isScary;
}

bool Ghost::isDead() const {
    return _isDead;
}


// Public Methods

void Ghost::update() {
    bool canMove { true };

    if (_isOnCell()) {
        setDirection(static_cast<Direction>(rand() % 4));

        _position = {
            static_cast<float>(static_cast<int>(_position.getX())),
            static_cast<float>(static_cast<int>(_position.getY()))
        };

        Vector2 nextPosition {_getNextPosition(_direction) };
        if (nextPosition.getX() < 0)
            _position.setX(_map->getSize().getX() - 1);
        else if (nextPosition.getX() >= _map->getSize().getX())
            _position.setX(0);
        else if (nextPosition.getY() < 0)
            _position.setY(_map->getSize().getY() - 1);
        else if (nextPosition.getY() >= _map->getSize().getY())
            _position.setY(0);

        if (_canMoveTo(_nextDirection) && directionToVector(_nextDirection) != -directionToVector(_direction)) {
            _direction = _nextDirection;
            if (!_isScary && !_isDead) {
                _updateImage();
            }
        }

        if (!_canMoveTo(_direction)) canMove = false;
    }

    if (canMove)
        setPosition(_position + _speed * directionToVector(_direction));

    if (_isScary) {
        ++_scareTime;
        if (_scareTime == (_scareDuration - 3) * static_cast<float>(config::WINDOW_FPS)) {
            _image = AnimatedImage("ghosts/scary/scary", _map->getCellSize() * 2, 4);
        }
        if (_scareTime == _scareDuration * static_cast<float>(config::WINDOW_FPS)) {
            _isScary = false;
            _image = AnimatedImage("ghosts/" + _name + "/" + _name + "_" + directionToName(_direction), _map->getCellSize() * 2);
            _updateImage();
        }
    }
    if (_isDead) {
        _image = AnimatedImage("ghosts/eyes/eyes_" + directionToName(_direction), _map->getCellSize() * 2, 1);
    }
    _image.updateFrame();
}

void Ghost::display(sf::RenderWindow& window) {
    _image.setPosition(_map->getPosition() + _map->getCellSize() * (_position - 0.5*Vector2::one()));
    _image.display(window);
}

void Ghost::scare() {
    _isScary = true;
    _scareTime = 0;
    _image = AnimatedImage("ghosts/scary/scary", _map->getCellSize() * 2);
}

void Ghost::die() {
    _isDead = true;
    _image = AnimatedImage("ghosts/eyes/eyes_" + directionToName(_direction), _map->getCellSize() * 2, 1);
}


// Protected Methods

void Ghost::_updateImage() {
    _image = AnimatedImage("ghosts/" + _name + "/" + _name + "_" + directionToName(_direction), _map->getCellSize() * 2);
    _image.setDuration(0.125);
}