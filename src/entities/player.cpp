#include "player.hpp"


// Constructors

Player::Player(std::shared_ptr<Map> map, const Vector2& position) :
    Entity(std::move(map), position),
    _image("pacman/walk/walk_" + directionToName(_direction), _map->getCellSize() * 2)
{
    _image.setDuration(0.125);
}


// Setters

void Player::setDirection(Direction direction) {
    if (!_isDead) {
//        Entity::setDirection(direction);
        _nextDirection = direction;
    }
}


// Public Methods

void Player::update() {
    if (!_isDead) {
        bool canMove { true };
        float intX { static_cast<float>(static_cast<int>(_position.getX())) },
              intY { static_cast<float>(static_cast<int>(_position.getY())) };

        if (intX - _speed < _position.getX() && _position.getX() < intX + _speed &&
                intY - _speed < _position.getY() && _position.getY() < intY + _speed) {
            _position = { intX, intY };
            std::string tile { _map->getTileAt(_position) };
            if (tile == "pacgum" || tile == "super_pacgum") {
                _map->removeElementAt(_position);
            }

            Vector2 newPos { _position + directionToVector(_direction) };
            std::string newTile { _map->getTileAt(newPos) };
            if (newTile.substr(0, 5) == "walls" || newTile.substr(0, 11) == "center_cell") {
                canMove = false;
            }

            if (_direction != _nextDirection) {
                newPos = _position + directionToVector(_nextDirection);
                newTile = _map->getTileAt(newPos);
                if (newTile.substr(0, 5) != "walls" && newTile.substr(0, 11) != "center_cell") {
                    _direction = _nextDirection;
                    _updateImage();
                    canMove = true;
                }
            }
        }

        if (canMove) {
            setPosition(_position + _speed * directionToVector(_direction));
            if (!_image.hasFinished()) {
                _image.updateFrame();
            }
        }
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
    _image.setDuration(0.125);
}

