#pragma once

#include "entity.hpp"
#include "display/animated_image.hpp"
#include "direction.hpp"
#include "utils/rect.hpp"


class Player final : public Entity {

public:
    // Constructors
    Player(std::shared_ptr<Map> map, const Vector2& position);

    // Getters
    bool hasFinished() const;

    // Setters
    void setDirection(Direction direction) override;

    // Public Methods
    void update() override;
    void display(sf::RenderWindow& window) override;
    void kill();
    bool hasAteSuperPacgum() const;

private:
    // Private Methods
    void _updateImage() override;

    // Attributes
    AnimatedImage _image;
    bool _isDead { false };
    bool _hasAteSuperPacgum { false };
    bool _hasFinished { false };

};
