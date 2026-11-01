#pragma once
#include "screen.h"
#include "grid.h"
#include "text_renderer.h"
#include "resource_manager.h"

class GamePlayScreen : public Screen
{
private:
    Grid grid;

public:
    GamePlayScreen(GLFWwindow *window);
    void draw() override;
    void update(float deltaTime) override;
};