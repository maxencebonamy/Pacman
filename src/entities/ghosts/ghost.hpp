#pragma once

#include "entities/entity.hpp"
#include "images/animated_image.hpp"


class Ghost : public Entity {

public:
    // Constructors
    Ghost(std::shared_ptr<Map> map, const Vector2& position, std::string name);

    // Big Five
    Ghost(const Ghost& ghost) = default;
    Ghost(Ghost&& ghost) noexcept = default;
    Ghost& operator=(const Ghost& ghost) = default;
    Ghost& operator=(Ghost&& ghost) noexcept = default;
    ~Ghost() override = default;

    // Public Methods
    void update() override;
    void display(sf::RenderWindow& window) override;

protected:
    // Attributes
    std::string _name;
    AnimatedImage _image;

};
