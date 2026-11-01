#pragma once
#include <string>
#include "glm/gtc/matrix_transform.hpp"
#include "text_renderer.h"
#include "sprite_renderer.h"
#include "resource_manager.h"

class Button
{
public:
    glm::vec2 position;
    glm::vec2 size;
    std::string text;
    Button() = default;
    Button(glm::vec2 position, glm::vec2 size, std::string text);
    void handleHover();
    void handleClick();

    void update(float deltaTime);
    void draw();
};