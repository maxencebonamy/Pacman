#pragma once

#include "entity.hpp"
#include "images/animated_image.hpp"
#include "direction.hpp"


class Player : public Entity {

public:
    // Constructors
    Player(std::shared_ptr<Map> map, const Vector2& position);

    // Setters
    void setDirection(Direction direction) override;

    // Public Methods
    void update() override;
    void display(sf::RenderWindow& window) override;
    void kill();

private:
    // Private Methods
    void _updateImage();

    // Attributes
    AnimatedImage _image;
    float _speed { 0.1 };
    bool _isDead { false };

};
