#pragma once

#include <memory>

#include "config.hpp"
#include "map/map.hpp"
#include "direction.hpp"


class Entity {

public:
    // Constructors
    Entity(std::shared_ptr<Map> map, const Vector2& position);

    // Big Five
    Entity(const Entity& entity) = default;
    Entity(Entity&& entity) noexcept = default;
    Entity& operator=(const Entity& entity) = default;
    Entity& operator=(Entity&& entity) noexcept = default;
    virtual ~Entity() = default;

    // Getters
    virtual const Vector2& getPosition() const;

    // Setters
    virtual void setPosition(const Vector2& position);
    virtual void setDirection(Direction direction);

    // Public Methods
    virtual void update() = 0;
    virtual void display(sf::RenderWindow& window) = 0;

protected:
    // Protected Methods
    bool _isOnCell() const;
    Vector2 _getNextPosition(Direction direction) const;
    bool _canMoveTo(Direction direction) const;
    virtual void _updateImage() = 0;

    // Attributes
    std::shared_ptr<Map> _map;
    Vector2 _position;
    Direction _direction;
    Direction _nextDirection;
    float _speed { 0.1f * 60.f / static_cast<float>(config::WINDOW_FPS) };

};
