#include "gameplay_screen.h"

GamePlayScreen::GamePlayScreen(GLFWwindow *window) : Screen(window)
{
    grid = Grid(800, 600, 2, 2);
}

void GamePlayScreen::update(float deltaTime)
{
    grid.update(deltaTime);

    // if (grid.solved)
    // {

    //     TextRenderer::renderText(ResourceManager::GetShader("text"), "You win", 400.0f, 300.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
    // }
}

void GamePlayScreen::draw()
{
    grid.draw();
}