#pragma once

#include "screen.h"
#include "ui_button.h"
#include "game.h"
#include "container.h"

class MainMenuScreen : public Screen
{
public:
    Button startButton;
    Button quitButton;
    Container background;
    void draw() override;
    void update(float deltaTime) override;
    Game *game;
    MainMenuScreen(GLFWwindow *window, Game *game);
};