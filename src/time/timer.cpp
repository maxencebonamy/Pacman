#include "timer.hpp"


// Constructors

Timer::Timer(float max) :
    _value(0),
    _max(static_cast<int>(max * static_cast<float>(config::WINDOW_FPS))),
    _hasFinished(false)
{}


// Getters

bool Timer::hasFinished() const {
    return _hasFinished;
}


// Public Methods

void Timer::update() {
    if (!_hasFinished) {
        if (++_value >= _max) {
            _hasFinished = true;
        }
    }
}

bool Timer::isAt(float value) const {
    return static_cast<float>(_value) == value * static_cast<float>(config::WINDOW_FPS);
}