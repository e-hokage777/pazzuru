#include "screen_manager.h"

// ScreenManager::ScreenManager(GLFWwindow *window): window(window) {

// }

void ScreenManager::setScreen(std::unique_ptr<Screen> screen)
{
    if (currentScreen)
    {
        currentScreen->cleanUp();
    }

    currentScreen = std::move(screen);
    // initiailize current screen if necessary
}

void ScreenManager::update(float deltaTime)
{
    if (currentScreen)
    {
        currentScreen->update(deltaTime);
    }
}

void ScreenManager::render()
{
    if (currentScreen)
    {
        currentScreen->render();
    }
}