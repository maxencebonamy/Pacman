#pragma once

#include <string>

#include "image.hpp"
#include "config.hpp"


class AnimatedImage final {

public:
    // Constructors
    AnimatedImage(const std::string& name, float size, int nbFrames=2);
    AnimatedImage(const std::vector<std::string>& names, float size);

    // Big Five
    AnimatedImage(const AnimatedImage& animatedImage) = default;
    AnimatedImage(AnimatedImage&& animatedImage) noexcept = default;
    AnimatedImage& operator=(const AnimatedImage& animatedImage) = default;
    AnimatedImage& operator=(AnimatedImage&& animatedImage) noexcept = default;
    ~AnimatedImage() = default;

    // Getters
    bool hasFinished() const;

    // Setters
    void disableLoop();
    void setDuration(float time);

    // Public Methods
    void display(sf::RenderWindow& window) const;
    void setPosition(const Vector2& position);
    void updateFrame();

private:
    // Attributes
    int _nbFrames;
    bool _loop { true };
    bool _hasFinished { false };
    float _duration { 0.25 };

    int _animationIndex { 1 };
    int _currentFrame { 1 };
    std::vector<Image> _images;

};
