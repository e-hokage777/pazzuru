#include "mainmenu_screen.h"

MainMenuScreen::MainMenuScreen(GLFWwindow *window, Game *game) : Screen(window), game(game)
{
    startButton = Button(glm::vec2(450.0f, 400.0f),
                         glm::vec2(200.0f, 100.0f),
                         "Start Game",
                         [game]()
                         { game->setState(Game::State::GAME_STARTED); });
    quitButton = Button(glm::vec2(400.0f, 300.0f),
                        glm::vec2(200.0f, 100.0f),
                        "Quit",
                        [game]()
                        { game->quit(); });
}

void MainMenuScreen::draw()
{
    startButton.draw();
    quitButton.draw();
}

void MainMenuScreen::update(float deltaTime)
{
    startButton.update(deltaTime);
    quitButton.update(deltaTime);
}