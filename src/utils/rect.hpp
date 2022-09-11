#pragma once

#include "vector2.hpp"


class Rect {

public:
    // Constructors
    Rect();
    Rect(float value);
    Rect(const Vector2& position, const Vector2& size);
    Rect(float x, float y, float w, float h);

    // Big Five
    Rect(const Rect& rect) = default;
    Rect(Rect&& rect) noexcept = default;
    Rect& operator=(const Rect& rect) = default;
    Rect& operator=(Rect&& rect) noexcept = default;
    ~Rect() = default;

    // Getters
    const Vector2& getPosition() const;
    const Vector2& getSize() const;
    Vector2 getEnd() const;
    Vector2 getCenter() const;

    // Setters
    void setPosition(const Vector2& position);
    void setSize(const Vector2& size);
    void setEnd(const Vector2& end);
    void setCenter(const Vector2& center);

    // Public Methods
    bool collide(const Vector2& point) const;
    bool collide(const Rect& rect) const;

private:
    // Attributes
    Vector2 _position;
    Vector2 _size;

};
