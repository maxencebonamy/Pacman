#include "image.hpp"


// Constructors

Image::Image(std::string name, float size) :
    _name(std::move(name)),
    _size(size)
{}


// Public Methods

void Image::init(const Vector2& position) {
    if (_name.empty()) {
        _texture.create(16, 16);
    }
    else {
        _texture.loadFromFile("res/img/map/" + _name + ".png");
    }

    setPosition(position);
}

void Image::setPosition(const Vector2& position) {
    _sprite = sf::Sprite(_texture);
    _sprite.setPosition(position.toSFML());
    _sprite.setScale(
        _size / static_cast<float>(_texture.getSize().x),
        _size / static_cast<float>(_texture.getSize().y)
    );
}

void Image::display(sf::RenderWindow& window) const {
    window.draw(_sprite);
}