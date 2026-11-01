#include "mainmenu_screen.h"

MainMenuScreen::MainMenuScreen(GLFWwindow *window):Screen(window)
{
    startButton = Button(glm::vec2(400.0f, 400.0f), glm::vec2(200.0f, 100.0f), "Start Game");
}

void MainMenuScreen::draw()
{
    startButton.draw();
}

void MainMenuScreen::update(float deltaTime)
{
    startButton.update(deltaTime);
}