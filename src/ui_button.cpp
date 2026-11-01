#include "ui_button.h"

Button::Button(glm::vec2 position, glm::vec2 size, std::string text) : position(position), size(size), text(text) {}

void Button::draw()
{
    SpriteRenderer::draw(ResourceManager::GetTexture("puzzle"), position - size * 0.5f, size);
    TextRenderer::renderText(ResourceManager::GetShader("text"), text, position.x - size.x * 0.5f, position.y, 1.0f, glm::vec3(1.0f, 0.5f, 0.8f));
}

void Button::update(float deltaTime)
{
}

void Button::handleClick()
{
}

void Button::handleHover()
{
}