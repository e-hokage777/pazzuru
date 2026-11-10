#pragma once
#include "screen.h"
#include "grid.h"
#include "text_renderer.h"
#include "resource_manager.h"
#include "container.h"
#include "ui_text.h"

class GamePlayScreen : public Screen
{
private:
    Grid grid;
    Container topNav;
    Container statusEl;
    Container background;
    Text *moveCount;

public:
    GamePlayScreen(GLFWwindow *window);
    void draw() override;
    void update(float deltaTime) override;
};