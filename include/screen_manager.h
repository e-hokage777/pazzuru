#pragma once
#include <memory>
#include "GLFW/glfw3.h"
#include "screen.h"

class ScreenManager
{
private:
    std::unique_ptr<Screen> currentScreen;
    // void clearBuffers();
    // void swapBuffers();
    // ScreenManager();

public:
    ScreenManager() = default;
    void setScreen(std::unique_ptr<Screen> screen);
    void update(float deltaTime);
    void render();
};