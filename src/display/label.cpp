#include "label.hpp"


// Constructors

Label::Label(std::string content, unsigned int size, const sf::Color& color) :
    _content(std::move(content))
{
    _font.loadFromFile("res/font/pacman.ttf");
    _text.setFont(_font);
    _text.setString(_content);
    _text.setCharacterSize(size);
    _text.setFillColor(color);

    sf::FloatRect textRect { _text.getLocalBounds() };
    _text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);

    _text.setPosition((config::WINDOW_SIZE / 2).toSFML());
}


// Setters

void Label::setContent(std::string content) {
    _content = std::move(content);
    _text.setString(_content);

    sf::FloatRect textRect { _text.getLocalBounds() };
    _text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);

    _text.setPosition((config::WINDOW_SIZE / 2).toSFML());
}


// Public Methods

void Label::display(sf::RenderWindow& window) const {
    window.draw(_text);
}