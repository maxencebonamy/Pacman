#pragma once

#include "config.hpp"


class Timer {

public:
    // Constructors
    explicit Timer(float max);

    // Big Five
    Timer(const Timer& timer) = default;
    Timer(Timer&& timer) noexcept = default;
    Timer& operator=(const Timer& timer) = default;
    Timer& operator=(Timer&& timer) noexcept = default;
    ~Timer() = default;

    // Getters
    bool hasFinished() const;

    // Public Methods
    void update();
    bool isAt(float value) const;

private:
    // Attributes
    unsigned int _value;
    unsigned int _max;
    bool _hasFinished;

};
