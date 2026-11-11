#pragma once
#include <string>
#include <memory>
#include "ui_element.h"
#include "resource_manager.h"
#include "text_renderer.h"

class Text : public UIElement
{
public:
    std::string text;
    glm::vec3 color;
    float scale;
    Text() = default;
    Text(float x, float y, float scale, std::string text, glm::vec3 color = glm::vec3(0.0f)) : UIElement(x, y, 1, 1), text(text), color(color), scale(scale)
    {
        shader = ResourceManager::GetShader("text");
        width = 0.0f;
        for (char c : this->text)
        {
            width += (TextRenderer::Characters.at(c).Advance >> 6) * scale;
        }
    }

    void draw() override
    {
        TextRenderer::renderText(
            shader,
            text, x, y, scale, color);
    }

private:
    Shader shader;
};