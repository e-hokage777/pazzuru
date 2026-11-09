#include "gameplay_screen.h"

GamePlayScreen::GamePlayScreen(GLFWwindow *window) : Screen(window)
{
    grid = Grid(100, 0, 600, 400, 2, 2);
    statusEl = UIElement(0.0f, 0.0f, 50.0f, 50.0f);
    topNav = UIElement(100.0f, 425.0f, 600.0f, 150.0f, glm::vec3(1.0f, 0.0f, 0.89f));
    topNav.add(UIElement(0.0f, 0.0f, 50.0f, 50.0f));
    topNav.add(UIElement(0.0f, 0.0f, 50.0f, 50.0f));
    topNav.add(UIElement(0.0f, 0.0f, 50.0f, 50.0f));
    background = UIElement(0, 0, 800, 600, ResourceManager::GetTexture("background"), glm::vec3(0.3f));
}

void GamePlayScreen::update(float deltaTime)
{
    grid.update(deltaTime);
    topNav.update(deltaTime);

    // if (grid.solved)
    // {

    //     TextRenderer::renderText(ResourceManager::GetShader("text"), "You win", 400.0f, 300.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
    // }
}

void GamePlayScreen::draw()
{
    background.draw();
    grid.draw();
    topNav.draw();
}