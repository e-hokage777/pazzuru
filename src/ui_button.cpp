#include "ui_button.h"
#include "input_manager.h"

Button::Button(glm::vec2 position, glm::vec2 size, std::string text, std::function<void()> onClick) : position(position), size(size), text(text), onClick(onClick) {}

void Button::draw()
{
    SpriteRenderer::draw(ResourceManager::GetTexture("puzzle"), position - size * 0.5f, size);
    TextRenderer::renderText(ResourceManager::GetShader("text"), text, position.x - size.x * 0.5f, position.y, 1.0f, glm::vec3(1.0f, 0.5f, 0.8f));
}

void Button::handleInput()
{
    if (InputManager::MouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
    {
        float mouseX = InputManager::GetMouseX();
        float mouseY = InputManager::GetOpenGLMouseY();

        if (mouseX > position.x - size.x * 0.5f &&
            mouseX < position.x + size.x * 0.5f &&
            mouseY > position.y - size.y * 0.5f &&
            mouseY < position.y + size.y * 0.5f)
        {
            onClick();
        }
    }
}

void Button::handleHover()
{
}


void Button::update(float deltaTime)
{
    handleInput();
}