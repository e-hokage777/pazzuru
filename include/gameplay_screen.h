#pragma once
#include "screen.h"
#include "grid.h"
#include "text_renderer.h"
#include "resource_manager.h"
#include "ui_element.h"

class GamePlayScreen : public Screen
{
private:
    Grid grid;
    UIElement topNav;
    UIElement statusEl;
    UIElement background;

public:
    GamePlayScreen(GLFWwindow *window);
    void draw() override;
    void update(float deltaTime) override;
};