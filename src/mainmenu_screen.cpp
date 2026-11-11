#include "mainmenu_screen.h"

MainMenuScreen::MainMenuScreen(GLFWwindow *window, Game *game) : Screen(window), game(game)
{
    startButton = Button(glm::vec2(400.0f, 400.0f),
                         glm::vec2(200.0f, 100.0f),
                         "Start Game",
                         [game]()
                         { game->setState(Game::State::LEVEL_SELECTION); });
    quitButton = Button(glm::vec2(400.0f, 250.0f),
                        glm::vec2(200.0f, 100.0f),
                        "Quit",
                        [game]()
                        { game->quit(); });

    background = Container(0, 0, 800, 600, ResourceManager::GetTexture("mm-background"), glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
}

void MainMenuScreen::draw()
{
    background.draw();
    startButton.draw();
    quitButton.draw();
}

void MainMenuScreen::update(float deltaTime)
{
    startButton.update(deltaTime);
    quitButton.update(deltaTime);
}