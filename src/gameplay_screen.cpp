#include "gameplay_screen.h"

GamePlayScreen::GamePlayScreen(GLFWwindow *window) : Screen(window)
{
    grid = Grid(100, 100, 600, 400, 5, 5);
    statusEl = Container(0.0f, 0.0f, 50.0f, 50.0f);
    auto text = std::make_unique<Text>(
        0, 0, 1.0f, std::to_string(grid.moves),
        glm::vec3(0.0f, 1.0f, 0.0f));
    moveCount = text.get();
    topNav = Container(100.0f, 520.0f, 600.0f, 70.0f);
    topNav.add(std::make_unique<Container>(0.0f, 0.0f, 50.0f, 50.0f, glm::vec4(1.0f)));
    topNav.add(std::move(text));
    topNav.add(std::make_unique<Container>(0.0f, 0.0f, 50.0f, 50.0f, ResourceManager::GetTexture("puzzle")));
    background = Container(0, 0, 800, 600, ResourceManager::GetTexture("background"), glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
}

void GamePlayScreen::update(float deltaTime)
{
    grid.update(deltaTime);
    topNav.update(deltaTime);
    moveCount->text = std::to_string(grid.moves);

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