#pragma once

#include "config.hpp"


class Label {

public:
    // Constructors
    explicit Label(std::string content, unsigned int size = 400, const sf::Color& color = {255, 204, 0});

    // Big Five
    Label(const Label& label) = default;
    Label(Label&& label) noexcept = default;
    Label& operator=(const Label& label) = default;
    Label& operator=(Label&& label) noexcept = default;
    ~Label() = default;

    // Setters
    void setContent(std::string content);

    // Public Methods
    void display(sf::RenderWindow& window) const;

private:
    // Attributes
    std::string _content;
    sf::Font _font;
    sf::Text _text;

};
