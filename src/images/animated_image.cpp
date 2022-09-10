#include "animated_image.hpp"


// Constructors

AnimatedImage::AnimatedImage(const std::string& name, float size, int nbFrames) :
    _nbFrames(nbFrames)
{
    for (int i { 1 }; i <= _nbFrames; ++i) {
        _images.emplace_back(name + '_' + std::to_string(i), size);
    }
}

AnimatedImage::AnimatedImage(const std::vector<std::string>& names, float size) :
    _nbFrames(static_cast<int>(names.size()))
{
    for (const auto& element : names) {
        _images.emplace_back(element, size);
    }
}


// Getters

bool AnimatedImage::hasFinished() const {
    return _hasFinished;
}


// Setters

void AnimatedImage::disableLoop() {
    _loop = false;
}

void AnimatedImage::setDuration(float duration) {
    _duration = duration;
}


// Public Methods

void AnimatedImage::display(sf::RenderWindow& window) const {
    _images[_currentFrame - 1].display(window);
}

void AnimatedImage::setPosition(const Vector2& position) {
    _images[_currentFrame - 1].setPosition(position);
}

void AnimatedImage::updateFrame() {
    ++_animationIndex;

    if (static_cast<float>(_animationIndex) >= static_cast<float>(config::WINDOW_FPS) * _duration) {
        _animationIndex = 1;

        if (_currentFrame < _nbFrames) {
            ++_currentFrame;
        }
        else if (_loop) {
            _currentFrame = 1;
        }
        else {
            _hasFinished = true;
        }
    }
}
