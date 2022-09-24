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
    if (_hasAteSuperPacgum) {
        _hasAteSuperPacgum = false;
    }

    if (!_isDead) {
        bool canMove { true };

        if (_isOnCell()) {
            _position = {
                static_cast<float>(static_cast<int>(_position.getX())),
                static_cast<float>(static_cast<int>(_position.getY()))
            };

            Vector2 nextPosition {_getNextPosition(_direction) };
            if (nextPosition.getX() < 0) _position.setX(_map->getSize().getX() - 1);
            else if (nextPosition.getX() >= _map->getSize().getX()) _position.setX(0);
            else if (nextPosition.getY() < 0) _position.setY(_map->getSize().getY() - 1);
            else if (nextPosition.getY() >= _map->getSize().getY()) _position.setY(0);

            std::string tile { _map->getTileAt(_position) };
            if (tile == "pacgum" || tile == "super_pacgum") {
                _map->removeElementAt(_position);
                if (tile == "super_pacgum") {
                    _hasAteSuperPacgum = true;
                }
            }

            if (!_canMoveTo(_direction)) canMove = false;

            if (_direction != _nextDirection) {
                if (_canMoveTo(_nextDirection)) {
                    _direction = _nextDirection;
                    _updateImage();
                    canMove = true;
                }
            }
        }

        if (canMove) {
            setPosition(_position + _speed * directionToVector(_direction));
        }
        else {
            _image = AnimatedImage({"pacman/walk/walk_" + directionToName(_direction)}, _map->getCellSize() * 2);
        }
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

bool Player::hasAteSuperPacgum() const {
    return _hasAteSuperPacgum;
}


// Private Methods

void Player::_updateImage() {
    _image = AnimatedImage("pacman/walk/walk_" + directionToName(_direction), _map->getCellSize() * 2);
    _image.setDuration(0.125);
}

