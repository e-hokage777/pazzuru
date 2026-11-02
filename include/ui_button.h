#pragma once
#include <string>
#include <functional>
#include "glm/gtc/matrix_transform.hpp"
#include "text_renderer.h"
#include "sprite_renderer.h"
#include "resource_manager.h"

class Button
{
private:
    void handleHover();
    void handleInput();

public:
    glm::vec2 position;
    glm::vec2 size;
    std::string text;
    std::function<void()> onClick;
    Button() = default;
    Button(glm::vec2 position, glm::vec2 size, std::string text, std::function<void()> onClick = nullptr);

    void update(float deltaTime);
    void draw();
};