#pragma once

class UIElement
{
public:
    float x, y, width, height;
    UIElement() : UIElement(0.0f, 0.0f, 0.0f, 0.0f) {}
    UIElement(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}
    virtual void update(float deltaTime){};
    virtual void draw(){};
    virtual ~UIElement() = default;
};