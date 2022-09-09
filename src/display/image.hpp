#pragma once

#include <string>

#include "SFML/Graphics.hpp"
#include "vector/vector2.hpp"


class Image {

public:
    // Constructors
    explicit Image(std::string name, float size);

    // Big Five
    Image(const Image& image) = default;
    Image(Image&& image) noexcept = default;
    Image& operator=(const Image& image) = default;
    Image& operator=(Image&& image) noexcept = default;
    ~Image() = default;

    // Public Methods
    void init(const Vector2& position);
    void display(sf::RenderWindow& window) const;
    void setPosition(const Vector2& position);

private:
    std::string _name;
    sf::Texture _texture;
    sf::Sprite _sprite;

    float _size;

};
