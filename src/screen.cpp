#include "screen.h"

Screen::Screen(GLFWwindow *window) : window(window)
{
    // create framebuffers and textures;
}

void Screen::clear()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::swapBuffers()
{
    glfwSwapBuffers(window);
}

void Screen::render()
{
    clear();
    // ResourceManager::GetShader("screen").use();
    draw();
    swapBuffers();
}

void Screen::cleanUp()
{
}

void Screen::update(float deltaTime) {}
void Screen::draw() {}
