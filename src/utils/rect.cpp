#include "rect.hpp"


// Constructors

Rect::Rect() :
    _position(),
    _size()
{}

Rect::Rect(float value) :
    _position(value),
    _size(value)
{}

Rect::Rect(const Vector2& position, const Vector2& size) :
    _position(position),
    _size(size)
{}

Rect::Rect(float x, float y, float w, float h) :
    _position(x, y),
    _size(w, h)
{}


// Getters

const Vector2& Rect::getPosition() const {
    return _position;
}

const Vector2& Rect::getSize() const {
    return _size;
}

Vector2 Rect::getEnd() const {
    return _position + _size;
}

Vector2 Rect::getCenter() const {
    return _position + _size / 2;
}


// Setters

void Rect::setPosition(const Vector2& position) {
    _position = position;
}

void Rect::setSize(const Vector2& size) {
    _size = size;
}

void Rect::setEnd(const Vector2& end) {
    _position = end - _size;
}

void Rect::setCenter(const Vector2& center) {
    _position = center - _size / 2;
}


// Public Methods

bool Rect::collide(const Vector2& point) const {
    return _position.getX() <= point.getX() && point.getX() <= getEnd().getX() &&
           _position.getY() <= point.getY() && point.getY() <= getEnd().getY();
}

bool Rect::collide(const Rect& rect) const {
    return collide(rect._position) || collide(rect._position + Vector2::unitX() * rect._size.getX()) ||
           collide(rect.getEnd()) || collide(rect._position + Vector2::unitY() * rect._size.getY()) ||
           rect.collide(_position) || rect.collide(_position + Vector2::unitX() * _size.getX()) ||
           rect.collide(getEnd()) || rect.collide(_position + Vector2::unitY() * _size.getY());
}