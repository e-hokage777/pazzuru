#include "mainmenu_screen.h"

MainMenuScreen::MainMenuScreen(GLFWwindow *window, Game *game) : Screen(window), game(game)
{
    startButton = Button(glm::vec2(400.0f, 400.0f),
                         glm::vec2(200.0f, 100.0f),
                         "Start Game",
                         [game]()
                         { game->setState(Game::State::GAME_STARTED); });
}

void MainMenuScreen::draw()
{
    startButton.draw();
}

void MainMenuScreen::update(float deltaTime)
{
    startButton.update(deltaTime);
}