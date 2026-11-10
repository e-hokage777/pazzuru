#pragma once

#include <vector>
#include <memory>
#include "glm/gtc/matrix_transform.hpp"
#include "texture.h"
#include "ui_element.h"

class Container : public UIElement
{
public:
    glm::vec3 bgColor;
    Texture sprite;
    bool useSprite = false;
    Container() = default;
    Container(float x, float y, float width, float height, glm::vec3 bgColor = glm::vec3(1.0f, 1.0f, 1.0f));
    Container(float x, float y, float width, float height, Texture sprite, glm::vec3 bgColor = glm::vec3(1.0f, 1.0f, 1.0f));
    void add(std::unique_ptr<UIElement> child, float px = 0, float py = 0);
    void update(float deltaTime) override;
    void draw() override;

private:
    std::vector<std::unique_ptr<UIElement>> children;

protected:
    void drawChildren();
    void updateChildren(float deltaTime);
};