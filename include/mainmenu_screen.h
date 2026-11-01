#pragma once

#include "screen.h"
#include "ui_button.h"

class MainMenuScreen : public Screen
{
public:
    Button startButton;
    void draw() override;
    void update(float deltaTime) override;
    MainMenuScreen(GLFWwindow *window);
};